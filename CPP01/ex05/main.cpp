#include "Harl.hpp"

int main ( void ){

    std::string input;
    //variável para receber o input do usuário
    Harl harl;
    //cria um objeto da classe Harl
    while(1){
        //loop infinito
        std::cout << "Enter a level (or exit to quit): ";
        //imprime na tela para o usuário digitar o level
        std::cin >> input;
        //pega o input do usuário e armazena na variável input
        if (input == "EXIT")
        //se o input do usuário for EXIT
            return 1;
            //retorna 1
        if (input != "DEBUG" || input != "INFO" || input != "WARNING" || input != "ERROR")
        //se o input do usuário for diferente de DEBUG, INFO, WARNING ou ERROR
            std::cout << "Error. Level is not exist. Try again, choose between (DEBUG, INFO, WARNING, ERROR or EXIT)." << std::endl;
            //imprime na tela que o level não existe

        harl.complain(input);
        //chama o método complain da classe Harl e passa o input do usuário como parâmetro. Resumindo, o método complain vai imprimir na tela o level e a mensagem correspondente.
    }
    return 0;
}