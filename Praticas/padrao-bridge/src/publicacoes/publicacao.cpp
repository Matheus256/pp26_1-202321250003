#include <string>

#include "publicacao.hpp"
#include "../implementacoes/implementador.hpp"

// Publicacao::Publicacao(Implementador* imp) : imp(imp) {}

std::string Publicacao::obterDados(){
    return imp->getDados(*this);
}