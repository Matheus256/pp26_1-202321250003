#include <format>

#include "shared/logger.hpp"
#include "shared/settings.hpp"
#include "subsystems/debate/debate.hpp"
#include "subsystems/debate/flow_state.hpp"
#include "subsystems/debate/reply_state.hpp"
#include "subsystems/mannager/inquirer_builder.hpp"
#include "subsystems/mannager/responder_builder.hpp"


void DebateMediator::setInquisitor(const PoliticalCollaborator* political)
{
    if (inquisitor != nullptr) {
        if (inquisitor->getMicrofone() != nullptr)
            delete inquisitor->getMicrofone();
        delete inquisitor;
    }

    inquisitor = InquirerBuilder(political)
                    .createMicrofone()
                    ->createCollaborator();
}

void DebateMediator::setResponder(const PoliticalCollaborator* political)
{
    if (responder != nullptr) {
        if (responder->getMicrofone() != nullptr)
            delete responder->getMicrofone();
        delete responder;
    }

    responder = ResponderBuilder(political)
                    .createMicrofone()
                    ->createCollaborator();
}

void DebateMediator::setState(DebateState* debateState){
    if (state != nullptr){
        delete state;
    }

    state = debateState;
}

void DebateMediator::replyRightEnqueue(PoliticalCollaborator* political){
    responder = ResponderBuilder(political)
                    .createMicrofone()
                    ->createCollaborator();
    replyRightQueue.push_back(responder);
}

std::vector<ResponderCollaborator*>& DebateMediator::getReplyRightQueue() {
    return replyRightQueue;
}

void DebateMediator::clearReplyRightQueue() {
    //for (auto pointer : replyRightQueue) {
    //    delete pointer; // Libera a memória
    //}
    replyRightQueue.clear(); // Limpa o vetor de ponteiros
}


void DebateMediator::debate(const TimeSettings* timeSettings) {
    state->run(timeSettings);
}