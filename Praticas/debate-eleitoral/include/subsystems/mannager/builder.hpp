#pragma once

#include "subsystems/debate/political.hpp"
#include "shared/microfone.hpp"


class CollaboratorBuilder {
protected:
    const PoliticalCollaborator* base;
    Microfone* micro;

public:
    CollaboratorBuilder(const PoliticalCollaborator* p) : base(p), micro(nullptr) {}

    CollaboratorBuilder* createMicrofone();

    virtual PoliticalCollaborator* createCollaborator() const = 0;
};
