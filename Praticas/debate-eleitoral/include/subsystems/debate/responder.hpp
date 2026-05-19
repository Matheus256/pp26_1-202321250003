#pragma once

#include <string>

#include "shared/microfone.hpp"
#include "subsystems/debate/political.hpp"

class ResponderCollaborator : public PoliticalCollaborator {
private:
    Microfone* microfe;

public:
    // Construtor comum
    ResponderCollaborator(const std::string& name, const std::string& party)
        : PoliticalCollaborator(name, party) {}

    
    // Construtor sobrecarregado
    ResponderCollaborator(
        const PoliticalCollaborator* political
    )
        : PoliticalCollaborator(political) {}
    
    void setMicrofone(Microfone* micro) {
        microfe = micro;
    }

    Microfone* getMicrofone() const {
        return microfe;
    }

    void speak(float time);
};