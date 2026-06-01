#include "subsystems/debate/responder.hpp"

void ResponderCollaborator::speak(float time) {
    notify();
    microfe->activate();
    microfe->waitTime(time);
    microfe->deactivate();
}

ResponderCollaborator* ResponderCollaborator::clone() const {
    return new ResponderCollaborator(this); 
}
