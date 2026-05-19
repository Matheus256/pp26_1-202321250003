#pragma once

#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream file;

    // Construtor privado
    Logger();

    // Impede cópia
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::string getCurrentTime();

public:
    ~Logger();

    // Acesso global ao singleton
    static Logger& getInstance();

    void info(const std::string& message);

    void error(const std::string& message);
};