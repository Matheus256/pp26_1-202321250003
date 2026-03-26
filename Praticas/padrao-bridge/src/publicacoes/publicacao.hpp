#pragma once

#include <string>

// Forward declaration
class Implementador;

class Publicacao{
    public:
        Publicacao(Implementador *imp): imp{imp}{};

        virtual std::string getTitulo() = 0;

        virtual std::string getAutor() = 0;

        std::string obterDados();

    private:
        Implementador *imp;
};