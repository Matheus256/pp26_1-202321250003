#include <iostream>
#include <sstream>

#include "shared/cli.hpp"
#include "shared/facade.hpp"
#include "shared/logger.hpp"


// Singleton
CLI& CLI::getInstance(Facade& facade)
{
    static CLI instance(facade);
    return instance;
}

// Construtor privado
CLI::CLI(Facade& facade) : facade(facade) {}

void CLI::run()
{
    std::string input;

    std::cout << "CLI iniciada. Digite 'ajuda' para ver os comandos disponiveis.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "sair") {
            Logger::getInstance().info("Comando exit para encerrar o sistema.");
            break;
        }

        // Quebra a string em argumentos
        std::istringstream iss(input);
        std::vector<std::string> args;
        std::string word;

        while (iss >> word) {
            args.push_back(word);
        }

        if (!args.empty()) {
            executarComando(args);
        }
    }
}

void CLI::executarComando(const std::vector<std::string>& args)
{
    // political create <name>,<party>
    if (args[0] == "criar" && args.size() >= 4 && args[1] == "politico") {
        facade.createPolitical(args[2], args[3]);
        std::cout << "  Politico criado." << std::endl;
    }

    // voter creat <name>,<political-name>,<political-party>
    else if (args[0] == "criar" && args.size() >= 5 && args[1] == "eleitor") {
        facade.createVoter(args[2], args[3], args[4]);
        std::cout << "  Eleitor criado." << std::endl;
    }

    // Set time settings
    else if (args[0] == "configurar" && args.size() >= 7 && args[1] == "tempos") {
        facade.defineTimeSettings(std::stof(args[2]), std::stof(args[3]), std::stof(args[4]), std::stof(args[5]), std::stof(args[6]));
        std::cout << "  Configurações de cronometro definidas com sucesso." << std::endl;
    }

    // Draw inquirer
    else if (args[0] == "sortear" && args.size() >= 2 && args[1] == "inquiridor") {
        std::string result = facade.drawnInquirer();
        std::cout << "  " << result << std::endl;
    }

    // Choose respondent
    else if(args[0] == "escolher" && args.size() >= 4 && args[1] == "inquirido") {
        std::string result = facade.chooseResponder(args[2], args[3]);
        std::cout << "  " << result << std::endl;
    }

    // Start debate session
    else if(args[0] == "iniciar" && args.size() >= 2 && args[1] == "debate") {
        facade.startDebate();
        std::cout << "  Realize agora a rodada de Direito de Resposta." << std::endl;
    }

    // Star reply right
    else if(args[0] == "iniciar" && args.size() >= 3 && args[1] == "direito" && args[2] == "resposta") {
        facade.startReplyRight();
        std::cout << "  Realize as definições do proximo debate." << std::endl;
    }

    // Help
    else if(args[0] == "ajuda" && args.size() >= 1) {
        
        std::cout << "  Lista de comandos do sistem:" << std::endl;
        std::cout << "      * criar politico <nome> <partido>" << std::endl;
        std::cout << "      * criar eleitor <nome> <nome-politico> <partido-politico>" << std::endl;
        std::cout << "      * configurar tempos <pergunta> <resposta> <replica> <treplica> <direito-resposta>" << std::endl;
        std::cout << "      * sortear inquiridor " << std::endl;
        std::cout << "      * escolher inquirido <nome-politico> <partido-politico> " << std::endl;
        std::cout << "      * iniciar debate " << std::endl;
        std::cout << "      * iniciar direito resposta " << std::endl;
        std::cout << "      * sair" << std::endl;
    }

    else {
        std::cout << "Comando inválido." << std::endl;
    }
}
