#pragma once

#include <string>

#include "implementador.hpp"

class PublicacaoImpXML: public Implementador{
    public:
        PublicacaoImpXML(){}

        std::string getDados(Publicacao &tipo){
            return "Obtem os dados do XML e seta";
        }
};