#pragma once

#include <string>

#include "shared/microfone.hpp"
#include "shared/prototype.hpp"
#include "subsystems/debate/mediator.hpp"
#include "subsystems/voter/publisher.hpp"


class PoliticalCollaborator : public Publisher, public Prototype {

private:
    std::string name;
    std::string party;
    Mediator* mediator;
    bool drawn;

public:
    // Construtor
    PoliticalCollaborator(const std::string& name, const std::string& party)
        : name(name),
          party(party),
          mediator(nullptr),
          drawn(false) {}


    // Constructor de copia
    PoliticalCollaborator(
        const PoliticalCollaborator* other
    )
        : Publisher(*other),
          name(other->name),
          party(other->party),
          mediator(other->mediator),
          drawn(other->drawn) {}

    bool getDrawn() const {
        return drawn;
    }

    
    void setDrawn(bool value) {
        drawn = value;
    }

    Mediator* getMediator() const{
        return mediator;
    }

    void setMediator(Mediator* m) {
        mediator = m;
    }

    void setParty(const std::string& p) {
        party = p;
    }

    std::string getParty() const {
        return party;
    }

    std::string getName() const {
        return name;
    }

    bool getMicrofoneStatus() const;

    PoliticalCollaborator* clone() const override;

};