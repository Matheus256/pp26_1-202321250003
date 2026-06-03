#include "subsystems/debate/political.hpp"
#include "subsystems/debate/responder.hpp"
#include "subsystems/mannager/responder_builder.hpp"


ResponderBuilder* ResponderBuilder::createMicrofone() {
    CollaboratorBuilder::createMicrofone();
    return this;
}

ResponderCollaborator* ResponderBuilder::createCollaborator() const {
    PoliticalCollaborator* copy = base->clone();
    auto* responder = new ResponderCollaborator(copy);
    delete copy;

    if (micro) responder->setMicrofone(micro);
    return responder;
}