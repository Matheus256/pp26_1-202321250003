#pragma once

#include <vector>
#include <algorithm>

#include "subsystems/voter/observer.hpp"

class Publisher {
private:
    std::vector<Observer*> voters;

public:
    // Adiciona observer
    void subscribe(Observer* observer);

    // Remove observer
    void unsubscribe(Observer* observer);

    // Notifica todos observers
    void notify();
};