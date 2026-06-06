#pragma once

#include "shared/settings.hpp"
#include "subsystems/debate/debate.hpp"
#include "subsystems/debate/debate_state.hpp"


class DebateReplyRightState: public DebateState {
private:
    DebateMediator* context;
public:
    DebateReplyRightState(DebateMediator* mediator) : context(mediator) {}
    void run(const TimeSettings* timeSettings) override;
};
