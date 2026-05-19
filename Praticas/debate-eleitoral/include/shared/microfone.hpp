#pragma once

#include <iostream>
#include <chrono>
#include <thread> 

class Microfone {
private:
    bool active;

public:
    // Construtor
    Microfone()
        : active(false) {}

    // Ativa o microfone
    void activate() {
        active = true;
    }

    // Desativa o microfone
    void deactivate() {
        active = false;
    }

    // Aguarda um tempo
    void waitTime(float time) {
        auto duracao = std::chrono::milliseconds(static_cast<int>(time * 1000));

        std::this_thread::sleep_for(duracao);
        std::cout << "  O microfe ativo pelo tempo de " << duracao << std::endl;
    }
};