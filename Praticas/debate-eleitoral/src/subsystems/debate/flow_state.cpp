#include <format>

#include "shared/logger.hpp"
#include "subsystems/debate/inquirer.hpp"
#include "subsystems/debate/flow_state.hpp"
#include "subsystems/debate/reply_state.hpp"
#include "subsystems/debate/responder.hpp"


void DebateFlowState::run(const TimeSettings* timeSettings){
    std::string log_mensagem;
    InquirerCollaborator* inquisitor = context->getInquisitor();
    ResponderCollaborator* responder = context->getResponder();

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

    context->setState(new DebateReplyRightState(context));
}

