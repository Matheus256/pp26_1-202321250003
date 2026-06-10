#pragma once

#include "shared/settings.hpp"
#include "subsystems/debate/debate.hpp"
#include "subsystems/debate/debate_state.hpp"


class DebateFlowState: public DebateState {
private:
    DebateMediator* context;
public:
    DebateFlowState(DebateMediator* mediator) : context(mediator) {}
    void run(const TimeSettings* timeSettings) override;
};
