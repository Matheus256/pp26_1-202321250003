#pragma once

#include "shared/settings.hpp"

class Mediator {
public:
    virtual ~Mediator() = default;

    virtual void debate(const TimeSettings* timeSettings) = 0;
};