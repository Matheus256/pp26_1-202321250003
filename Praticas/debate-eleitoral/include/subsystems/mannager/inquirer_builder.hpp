#pragma once

#include "subsystems/debate/inquirer.hpp"
#include "subsystems/debate/political.hpp"
#include "subsystems/mannager/builder.hpp"


class InquirerBuilder: public CollaboratorBuilder {
public:
    InquirerBuilder(const PoliticalCollaborator* political) : CollaboratorBuilder(political){}

    InquirerBuilder* createMicrofone();
    InquirerCollaborator* createCollaborator() const override;
};