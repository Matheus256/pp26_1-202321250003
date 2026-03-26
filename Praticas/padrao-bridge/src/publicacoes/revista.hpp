#pragma once

#include <string>

#include "publicacao.hpp"

class Revista: public Publicacao{
    public:
        Revista(Implementador *imp): Publicacao(imp){}

        std::string getArtigo(){
            return "Realiza getArtigo() da revista";
        }

        std::string getTitulo(){
            return "Realiza getTitulo() da revista";
        }

        std::string getAutor(){
            return "Realiza getAutor() da revista";
        }
};