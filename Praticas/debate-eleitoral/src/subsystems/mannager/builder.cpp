#include "shared/microfone.hpp"
#include "subsystems/mannager/builder.hpp"


CollaboratorBuilder* CollaboratorBuilder::createMicrofone(){
    this->micro = new Microfone();
    return this;
}