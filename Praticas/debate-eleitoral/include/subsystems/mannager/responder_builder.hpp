#pragma once

#include "subsystems/debate/political.hpp"
#include "subsystems/debate/responder.hpp"
#include "subsystems/mannager/builder.hpp"


class ResponderBuilder: public CollaboratorBuilder {
public:
    ResponderBuilder(const PoliticalCollaborator* political) : CollaboratorBuilder(political){}

    ResponderBuilder* createMicrofone();
    ResponderCollaborator* createCollaborator() const override;
};