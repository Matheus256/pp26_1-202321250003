#pragma once

#include <memory>
#include <string>

class TimeSettings;
class PoliticalManager;
class DebateMediator;

class Facade {
private:
    static Facade* instance;

    std::unique_ptr<TimeSettings> timeSettings;
    std::unique_ptr<PoliticalManager> politicalManager;
    std::unique_ptr<DebateMediator> debateMediator;

    // Construtor privado (Singleton)
    Facade() = default;

public:
    // Impede cópia
    Facade(const Facade&) = delete;
    Facade& operator=(const Facade&) = delete;

    static Facade& getInstance();

    // Inicializa sistema
    void init();

    // Acesso aos serviços
    TimeSettings& getTimeSettings();

    // Métodos principais
    void defineTimeSettings(float question, float answer, float reply, float counterReply);
    void createPolitical(const std::string name, const std::string party);
    void createVoter(const std::string name, const std::string politicalName, const std::string politicalParty);
    std::string drawnInquirer();
    std::string chooseResponder(const std::string name, const std::string party);
    void startDebate();
};