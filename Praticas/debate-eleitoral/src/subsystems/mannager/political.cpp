#include <cstdlib>
#include <format> 
#include <string>

#include "shared/logger.hpp"
#include "subsystems/mannager/political.hpp"
#include "subsystems/debate/debate.hpp"


// Adiciona político
void PoliticalManager::createPolitical(
    PoliticalCollaborator* political
) {
    politicals.push_back(political);
}

// Busca político pelo nome
PoliticalCollaborator* PoliticalManager::getPolitical(
    const std::string& name, const std::string& party 
) {
    for (auto& political : politicals) {
        if (political->getName() == name && political->getParty() == party)
            return political;
    }

    return nullptr;
}

void PoliticalManager::drawRequestReplyRight() const{
    std::string log_mensagem;

    for (auto* political : politicals) {
        bool op = std::rand() % 3; // 33%
        if (op == 1) {

            // Cast para usar replyRightEnqueue
            auto* debateMediator = dynamic_cast<DebateMediator*>(political->getMediator());
            if (debateMediator != nullptr) {
                debateMediator->replyRightEnqueue(political);
            }

            log_mensagem = std::format("O candidato {} do partido {} solicitou Direito de Resposta", political->getName(), political->getParty());
            Logger::getInstance().info(log_mensagem);
        }
    }
}

// Sorteia político
PoliticalCollaborator* PoliticalManager::drawnPolitical() {
    for (auto& political : politicals) {
        if (!political->getDrawn()) {
            political->setDrawn(true);

            totalDrawn++;

            return political;
        }
    }

    return nullptr;
}