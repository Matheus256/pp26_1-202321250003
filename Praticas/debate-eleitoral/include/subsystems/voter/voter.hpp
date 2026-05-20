#pragma once

#include <string>

#include "subsystems/debate/political.hpp"
#include "subsystems/voter/observer.hpp"


class VoterObserver : public Observer {
private:
    PoliticalCollaborator* political;
    bool politicalSpeeking;
    std::string name;

public:
    // Construtor
    VoterObserver(
        const std::string& name,
        PoliticalCollaborator* political
    )
        : political(political),
          politicalSpeeking(false),
          name(name) {}

    void setPoliticalSpeeking(bool state) {
        politicalSpeeking = state;
    }

    std::string getName() const {
        return name;
    }
    
    // Sobrescrita do método update
    void update() override;
};