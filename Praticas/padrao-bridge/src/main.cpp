#include <iostream>
#include <string>

#include "publicacoes/livro.hpp"
#include "publicacoes/revista.hpp"
#include "implementacoes/implementacao_bd.hpp"
#include "implementacoes/implementacao_xml.hpp"

void formataPrint(std::string texto);

int main(){

    std::cout << "Início do Sistema de Publicações:" << std::endl << std::endl;

    Livro livro{new PublicacaoImpBD};

    std::cout << "  > Publicação do tipo Livro:" << std::endl;
    formataPrint(livro.obterDados());
    formataPrint(livro.getTitulo());
    formataPrint(livro.getAutor());
    formataPrint(livro.getISBN());

    std::cout << std::endl;

    Revista revista{new PublicacaoImpXML};

    std::cout << "  > Publicação do tipo Revista:" << std::endl;
    formataPrint(revista.obterDados());
    formataPrint(revista.getTitulo());
    formataPrint(revista.getAutor());
    formataPrint(revista.getArtigo());

    return 0;
}

void formataPrint(std::string texto){
    std::cout << "      - " << texto << std::endl;
}