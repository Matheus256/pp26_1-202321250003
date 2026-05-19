#include <format>
#include <iostream>

#include "shared/logger.hpp"
#include "subsystems/voter/voter.hpp"

// Sobrescrita do método update
void VoterObserver::update() {
    // political_speeking = political->getMicrofoneStatus();
    std::string log_mensagem = std::format("Eleitor {} notificado que seu candidato está falando", name);
    std::cout << "      " << log_mensagem << std::endl;
    Logger::getInstance().info(log_mensagem);
}