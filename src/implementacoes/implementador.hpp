#pragma once

#include <string>

#include "../publicacoes/publicacao.hpp"

class Implementador{
    public:
        Implementador(){}

        virtual std::string getDados(Publicacao &tipo) = 0;
};