#pragma once

#include "shared/settings.hpp"


class DebateState {
public:
    virtual ~DebateState() = default;
    virtual void run(const TimeSettings* timeSettings) = 0;
};
