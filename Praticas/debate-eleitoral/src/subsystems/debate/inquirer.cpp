#include "subsystems/debate/inquirer.hpp"

void InquirerCollaborator::select_Inquirer(PoliticalCollaborator political) {
    // implementação futura
    // mediator->
}

void InquirerCollaborator::speak(float time) {
    notify();
    microfe->activate();
    microfe->waitTime(time);
    microfe->deactivate();
}