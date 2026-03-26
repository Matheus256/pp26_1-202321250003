#pragma once

#include <string>

#include "publicacao.hpp"

class Livro: public Publicacao{
    public:
        Livro(Implementador *imp): Publicacao(imp){}

        std::string getISBN(){
            return "Realiza getISBN() do livro";
        }

        std::string getTitulo(){
            return "Realiza getTitulo() do livro";
        }

        std::string getAutor(){
            return "Realiza getAutor() do livro";
        }
};