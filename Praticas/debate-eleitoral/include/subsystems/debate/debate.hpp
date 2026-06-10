#pragma once

#include <iostream>
#include <vector>

#include "shared/settings.hpp"
#include "subsystems/debate/debate_state.hpp"
#include "subsystems/debate/mediator.hpp"
#include "subsystems/debate/inquirer.hpp"
#include "subsystems/debate/responder.hpp"


class DebateMediator : public Mediator {
private:
    InquirerCollaborator* inquisitor;
    ResponderCollaborator* responder;
    DebateState* state;
    std::vector<ResponderCollaborator*> replyRightQueue;

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
    InquirerCollaborator* getInquisitor() const{return inquisitor;}

    // Setter de responder
    void setResponder(const PoliticalCollaborator* political);
    ResponderCollaborator* getResponder() const{return responder;}

    void setState(DebateState* debateState);

    void replyRightEnqueue(PoliticalCollaborator* political);

    std::vector<ResponderCollaborator*>& getReplyRightQueue();

    void clearReplyRightQueue();
};