#include "Harl.hpp"

//tudo igual ao ex05, só muda que agora usamos argc e argv para pegar o argumento passado pelo usuário ao invés de usar o input do usuário.
int main (int argc, char **argv){

    if (argc != 2){
        std::cout << "Error. Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string input = argv[1];
    Harl harl;

        if (input == "DEBUG" || input == "INFO" || input == "WARNING" || input == "ERROR")
            harl.complain(input);
        else
            std::cout << "Error. Level is not exist. Try again, choose between (DEBUG, INFO, WARNING, ERROR or EXIT)." << std::endl;
    return 0;
}
