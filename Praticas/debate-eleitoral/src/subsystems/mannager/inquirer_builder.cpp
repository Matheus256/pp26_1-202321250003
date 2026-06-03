#include "subsystems/debate/inquirer.hpp"
#include "subsystems/debate/political.hpp"
#include "subsystems/mannager/inquirer_builder.hpp"


InquirerBuilder* InquirerBuilder::createMicrofone() {
    CollaboratorBuilder::createMicrofone();
    return this;
}

InquirerCollaborator* InquirerBuilder::createCollaborator() const {
    // O Builder assume a responsabilidade do Clone
    PoliticalCollaborator* copy = base->clone();
    auto* inquisitor = new InquirerCollaborator(copy);
    delete copy; // Limpa a cópia temporária

    if (micro) inquisitor->setMicrofone(micro);
    return inquisitor;
}