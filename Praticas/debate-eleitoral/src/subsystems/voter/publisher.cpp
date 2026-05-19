#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "shared/logger.hpp"
#include "subsystems/voter/observer.hpp"
#include "subsystems/voter/publisher.hpp"

// Adiciona observer
void Publisher::subscribe(Observer* observer) {
    voters.push_back(observer);
}

// Remove observer
void Publisher::unsubscribe(Observer* observer) {
    voters.erase(
        std::remove(voters.begin(), voters.end(), observer),
        voters.end()
    );
}

// Notifica todos observers
void Publisher::notify() {
    for (Observer* voter : voters) {
        if (voter != nullptr) {
            voter->update();
        }
    }
    std::cout << "      Eleitoress notificados" << std::endl;
    Logger::getInstance().info("Eleitores notificados");
}