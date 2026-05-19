#include "subsystems/mannager/political.hpp"

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