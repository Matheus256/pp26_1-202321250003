#include <format>
#include <iostream>
#include <stdexcept>
#include <string>

#include "shared/facade.hpp"
#include "shared/logger.hpp"
#include "shared/settings.hpp"
#include "subsystems/debate/debate.hpp"
#include "subsystems/debate/flow_state.hpp"
#include "subsystems/debate/political.hpp"
#include "subsystems/mannager/political.hpp"
#include "subsystems/voter/voter.hpp"


// Inicialização do ponteiro estático
Facade* Facade::instance = nullptr;

Facade& Facade::getInstance()
{
    if (!instance) {
        instance = new Facade();
    }
    return *instance;
}

void Facade::init()
{
    // Inicializar instâncias necessárias
    timeSettings = std::make_unique<TimeSettings>();
    politicalManager = std::make_unique<PoliticalManager>();
    //debateMediator = std::make_unique<DebateMediator>();
    debateMediator = new DebateMediator();
    debateMediator->setState(new DebateFlowState(debateMediator));

    Logger::getInstance().info("Fachada iniciada");
}


TimeSettings& Facade::getTimeSettings()
{
    if (!timeSettings) {
        throw std::runtime_error("TimeSettings não inicializado. Chame init() primeiro.");
    }

    return *timeSettings;
}

void Facade::defineTimeSettings(float question, float answer, float reply, float counterReply, float replyRight)
{
    try {
        timeSettings->setQuestion(question);
        timeSettings->setAnswer(answer);
        timeSettings->setReply(reply);
        timeSettings->setCounterReply(counterReply);
        timeSettings->setReplyRight(replyRight);
        std::string log_mensagem = std::format("Define os tempos: Pergunta -> {}, Resposta -> {}, Replica -> {}, Treplica -> {}, Direito de Repostas -> ", question, answer, reply, counterReply, replyRight);
        Logger::getInstance().info(log_mensagem);
    } catch (...) {
        
        std::cerr << "Erro ao registrar tempos do debate!" << std::endl;
        Logger::getInstance().error("Erro ao registrar tempos do debate");
    }
}

void Facade::createPolitical(std::string name, std::string party){
    try {
        PoliticalCollaborator* political = new PoliticalCollaborator(name, party);
        political->setMediator(debateMediator);
        politicalManager->createPolitical(political);
        std::string log_mensagem = std::format("Politico {} do partido {} adicionado", name, party);
        Logger::getInstance().info(log_mensagem);
    } catch (...) {
        Logger::getInstance().error("Erro ao adicionar o novo político");
    }

}

void Facade::createVoter(std::string name, std::string politicalName, std::string politicalParty){
    try {
        PoliticalCollaborator* political = politicalManager->getPolitical(politicalName, politicalParty);
        VoterObserver *voter = new VoterObserver(name, political);
        political->subscribe(voter);
        std::string log_mensagem = std::format("Novo eleitor {} criado e vinculado ao politico {}", name, politicalName);
        Logger::getInstance().info(log_mensagem);

    } catch (...) {
        Logger::getInstance().error("Erro ao criar novo eleitor");
    }
}

std::string Facade::drawnInquirer() {
    std::string log_mensagem;
    PoliticalCollaborator* political = politicalManager->drawnPolitical();
    if (political != nullptr) {
        debateMediator->setInquisitor(political);
        log_mensagem = std::format(
            "Politico {} do partido {} será o inquiridor da rodada", 
            political->getName(), 
            political->getParty()
        );
        Logger::getInstance().info(log_mensagem);
        return log_mensagem;
    }
    
    log_mensagem = "Nao foi possivel sortear um novo politico";
    return log_mensagem;
}

std::string Facade::chooseResponder(const std::string name, const std::string party){
    std::string log_mensagem;
    try {
        PoliticalCollaborator* political = politicalManager->getPolitical(name, party);
        if (political != nullptr) {
            debateMediator->setResponder(political);
            log_mensagem = std::format("Politico {} do partido {} foi escolhido como inquirido", name, party);
            Logger::getInstance().info(log_mensagem);
            return log_mensagem;
        } else {
            log_mensagem = "Candidato não encontrado";
            Logger::getInstance().info(log_mensagem);
            return log_mensagem;
        }
        
    } catch (...) {
        log_mensagem = std::format("Erro ao obter e definir o politico {} do partido {}", name, party);
        Logger::getInstance().error(log_mensagem);
        return log_mensagem;
    }
}

void Facade::startDebate(){
    try {
        std::cout << "  Debate iniciado!" << std::endl;
        Logger::getInstance().info("Debate iniciado");

        debateMediator->debate(timeSettings.get());

        std::cout << "  Debate encerrado" << std::endl;
        Logger::getInstance().info("Debate encerrado");
        politicalManager->drawRequestReplyRight();
    } catch (...) {
        std::cout << "Erro no decorrer do debate" << std::endl;
        Logger::getInstance().error("Erro no decorrer do debate");
    }

}

void Facade::startReplyRight(){
    try {
        std::cout << "  Direito de Resposta iniciado!" << std::endl;
        Logger::getInstance().info("Direito de Resposta iniciado");

        debateMediator->debate(timeSettings.get());

        std::cout << "  Direito de Resposta encerrado" << std::endl;
        Logger::getInstance().info("Direito de Resposta encerrado");
    } catch (...) {
        std::cout << "Erro no decorrer do direiro de resposta" << std::endl;
        Logger::getInstance().error("Erro no decorrer do direiro de resposta");
    }

}
