#include "shared/facade.hpp"
#include "shared/cli.hpp"


int main() {
    auto& facade = Facade::getInstance();
    facade.init();

    auto& cli = CLI::getInstance(facade);
    cli.run();

    return 0;
}
