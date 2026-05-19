#pragma once

#include <string>
#include <vector>

class Facade;

class CLI {
private:
    Facade& facade;

    CLI(Facade& facade); // construtor privado

    void executarComando(const std::vector<std::string>& args);

public:
    static CLI& getInstance(Facade& facade);

    void run();
};
