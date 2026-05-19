#pragma once

class TimeSettings {
private:
    float question;
    float answer;
    float reply;
    float counterReply;

public:
    // Construtor padrão
    TimeSettings()
        : question(0.0f),
          answer(0.0f),
          reply(0.0f),
          counterReply(0.0f) {}

    // GETTERS

    float getQuestion() const {
        return question;
    }

    float getAnswer() const {
        return answer;
    }

    float getReply() const {
        return reply;
    }

    float getCounterReply() const {
        return counterReply;
    }

    // SETTERS

    void setQuestion(float value) {
        question = value;
    }

    void setAnswer(float value) {
        answer = value;
    }

    void setReply(float value) {
        reply = value;
    }

    void setCounterReply(float value) {
        counterReply = value;
    }
};