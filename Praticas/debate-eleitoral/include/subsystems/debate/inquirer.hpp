#pragma once

#include <string>

#include "subsystems/debate/political.hpp"

class InquirerCollaborator : public PoliticalCollaborator {
private:
    Microfone* microfe;

public:
    // Construtor comum
    InquirerCollaborator(const std::string& name, const std::string& party)
        : PoliticalCollaborator(name, party) {}

    
    // Construtor sobrecarregado
    InquirerCollaborator(
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