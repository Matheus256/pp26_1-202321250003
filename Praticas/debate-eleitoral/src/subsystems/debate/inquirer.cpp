#include "subsystems/debate/inquirer.hpp"


void InquirerCollaborator::speak(float time) {
    notify();
    microfe->activate();
    microfe->waitTime(time);
    microfe->deactivate();
}