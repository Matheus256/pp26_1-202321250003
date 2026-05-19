#pragma once

#include <string>

#include "subsystems/debate/political.hpp"
#include "subsystems/voter/observer.hpp"


class VoterObserver : public Observer {
private:
    PoliticalCollaborator* political;
    bool political_speeking;
    std::string name;

public:
    // Construtor
    VoterObserver(
        const std::string& name,
        PoliticalCollaborator* political
    )
        : political(political),
          political_speeking(false),
          name(name) {}

    void setPoliticalSpeeking(bool state) {
        political_speeking = state;
    }

    std::string getName() const {
        return name;
    }
    
    // Sobrescrita do método update
    void update() override;
};