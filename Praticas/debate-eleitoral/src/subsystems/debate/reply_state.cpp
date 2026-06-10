#include <format>
#include <iostream>
#include <string>

#include "shared/logger.hpp"
#include "subsystems/debate/reply_state.hpp"
#include "subsystems/debate/flow_state.hpp"


void DebateReplyRightState::run(const TimeSettings* timeSettings){
    std::string rightResult, log_mensagem;
    std::cout << "  Candidatos que solicitaram Direito de Resposta..." << std::endl;

    for (auto* political : context->getReplyRightQueue()) {
        std::cout << std::format("  O candidato {} do partido {} solicitou Direito de Resposta", political->getName(), political->getParty()) << std::endl;
        std::cout << "  Deseja conceder Direirto de resposta ao candidato (Sim / Não)?" << std::endl;
        std::cout << "> ";
        std::cin >> rightResult;
        if (rightResult == "Sim"){
            log_mensagem = std::format("O candidato {} Teve direito de resposta concedido", political->getName());
            Logger::getInstance().info(log_mensagem);
            std::cout << "  " << log_mensagem << std::endl;
            political->speak(timeSettings->getReplyRight());
        } else {
            log_mensagem = std::format("O candidato {} Teve direito de resposta negado", political->getName());
            Logger::getInstance().info(log_mensagem);
            std::cout << "  " << log_mensagem << std::endl;
        }
    }

    context->clearReplyRightQueue();
    context->setState(new DebateFlowState(context));
}