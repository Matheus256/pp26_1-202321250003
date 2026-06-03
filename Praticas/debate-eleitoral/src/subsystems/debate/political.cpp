#include "subsystems/debate/political.hpp"

bool PoliticalCollaborator::getMicrofoneStatus() const {
    return true;
}

PoliticalCollaborator* PoliticalCollaborator::clone() const {
    // Cria uma nova instância usando o construtor de cópia
    return new PoliticalCollaborator(*this);
}