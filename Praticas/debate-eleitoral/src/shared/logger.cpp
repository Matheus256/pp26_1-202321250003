#include "shared/logger.hpp"

#include <ctime>
#include <iostream>

Logger::Logger() {
    file.open("app.log", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo de log\n";
    }
}

Logger::~Logger() {
    if (file.is_open()) {
        file.close();
    }
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);

    char buffer[100];

    std::strftime(
        buffer,
        sizeof(buffer),
        "%Y-%m-%d %H:%M:%S",
        std::localtime(&now)
    );

    return buffer;
}

void Logger::info(const std::string& message) {
    if (file.is_open()) {
        file << "[" << getCurrentTime() << "] "
             << "[INFO] "
             << message
             << std::endl;
    }
}

void Logger::error(const std::string& message) {
    if (file.is_open()) {
        file << "[" << getCurrentTime() << "] "
             << "[ERROR] "
             << message
             << std::endl;
    }
}