#include <format>

#include "shared/logger.hpp"
#include "shared/settings.hpp"
#include "subsystems/debate/debate.hpp"

void DebateMediator::setInquisitor(const PoliticalCollaborator* political)
{
    if (inquisitor != nullptr) {
        if (inquisitor->getMicrofone() != nullptr)
            delete inquisitor->getMicrofone();
        delete inquisitor;
    }

    Microfone* micro = new Microfone();

    inquisitor = new InquirerCollaborator(political);
    inquisitor->setMicrofone(micro);
}

void DebateMediator::setResponder(const PoliticalCollaborator* political)
{
    if (responder != nullptr) {
        if (responder->getMicrofone() != nullptr)
            delete responder->getMicrofone();
        delete responder;
    }

    Microfone* micro = new Microfone();

    responder = new ResponderCollaborator(political);
    responder->setMicrofone(micro);
}

void DebateMediator::debate(const TimeSettings* timeSettings) {
    std::string log_mensagem;

    // FLuxo pergunta
    log_mensagem = std::format("O candidato {} está perguntando", inquisitor->getName());
    Logger::getInstance().info(log_mensagem);
    std::cout << "  " << log_mensagem << std::endl;
    inquisitor->speak(timeSettings->getQuestion());

    // FLuxo resposta
    log_mensagem = std::format("O candidato {} está respondendo", responder->getName());
    Logger::getInstance().info(log_mensagem);
    std::cout << "  " << log_mensagem << std::endl;
    responder->speak(timeSettings->getAnswer());

    // Fluxo replica
    log_mensagem = std::format("O candidato {} está fazendo a replica", inquisitor->getName());
    Logger::getInstance().info(log_mensagem);
    std::cout << "  " << log_mensagem << std::endl;
    inquisitor->speak(timeSettings->getReply());

    // Fluxo treplica
    log_mensagem = std::format("O candidato {} está fazendo a treplica", responder->getName());
    Logger::getInstance().info(log_mensagem);
    std::cout << "  " << log_mensagem << std::endl;
    responder->speak(timeSettings->getCounterReply());
}