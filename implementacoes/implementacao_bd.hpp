#pragma once

#include <string>

#include "implementador.hpp"

class PublicacaoImpBD: public Implementador{
    public:
        PublicacaoImpBD(){}
        
        std::string getDados(Publicacao &tipo){
            return "Obtem os dados do banco e seta";
        }
};