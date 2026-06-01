#include "subsystems/debate/inquirer.hpp"


void InquirerCollaborator::speak(float time) {
    notify();
    microfe->activate();
    microfe->waitTime(time);
    microfe->deactivate();
}

InquirerCollaborator* InquirerCollaborator::clone() const {
    return new InquirerCollaborator(this); 
}
