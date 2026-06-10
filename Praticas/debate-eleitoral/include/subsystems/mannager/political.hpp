#pragma once

#include <vector>
#include <string>

#include "subsystems/debate/political.hpp"

class PoliticalManager {
private:
    std::vector<PoliticalCollaborator*> politicals;
    int totalDrawn;

public:
    // Construtor
    PoliticalManager()
        : totalDrawn(0) {}

    // Adiciona político
    void createPolitical(PoliticalCollaborator* political);

    // Busca político pelo nome
    PoliticalCollaborator* getPolitical(const std::string& name, const std::string& party);

    // Sorteia político
    PoliticalCollaborator* drawnPolitical();

    void drawRequestReplyRight() const;
};