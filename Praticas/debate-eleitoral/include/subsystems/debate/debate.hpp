#pragma once

#include <iostream>

#include "shared/settings.hpp"
#include "subsystems/debate/mediator.hpp"
#include "subsystems/debate/inquirer.hpp"
#include "subsystems/debate/responder.hpp"

class DebateMediator : public Mediator {
private:
    InquirerCollaborator* inquisitor;
    ResponderCollaborator* responder;

public:
    // Construtor
    DebateMediator()
        : inquisitor(nullptr),
          responder(nullptr) {}

    // Destrutor
    ~DebateMediator() {
        delete inquisitor;
        delete responder;
    }

    // Sobrescrita do método debate
    void debate(const TimeSettings* timeSettings) override;

    // Setter de inquisitor
    void setInquisitor(const PoliticalCollaborator* political);

    // Setter de responder
    void setResponder(const PoliticalCollaborator* political);
};