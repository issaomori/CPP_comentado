#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat best("Best", 0);
        //tentando criar um burocrata com nota 0, mas não pode
    } catch (std::exception& e) {
        //como não pode criar um burocrata com nota 0, lança uma exceção
        std::cout << e.what() << std::endl;
        //e.what() retorna uma string que descreve o erro
    }

    try {
        //tento criar um burocrata com nota 200, mas não pode
        Bureaucrat worst("Worst", 200);
    } catch (std::exception& e) {
        //como não pode criar um burocrata com nota 200, lança uma exceção
        std::cout << e.what() << std::endl;
    }

    Bureaucrat high("High", 1);
    //crio um burocrata com nota 1 que é a nota mais alta
    Bureaucrat low("Low", 150);
    //crio um burocrata com nota 150 que é a nota mais baixa
    Bureaucrat medium("Medium", 75);
    //crio um burocrata com nota 75 que é uma nota intermediaria

    std::cout << std::endl;
    std::cout << "Bureaucrat grade:" << std::endl;
    std::cout << high;
    std::cout << medium;
    std::cout << low;
    std::cout << std::endl;
    //imprimo os burocratas

    std::cout << "Testing grade too high:" << std::endl;
    try {
        //tento incrementar a nota do burocrata high, mas não pode porque a nota dele já é a mais alta
        high.incrementGrade();
    } catch (std::exception& e) {
        //como não pode incrementar a nota do burocrata high, lança uma exceção
        std::cerr << e.what() << "\n";
    }

    std::cout << "Testing grade too low:" << std::endl;
    try {
        //tento decrementar a nota do burocrata low, mas não pode porque a nota dele já é a mais baixa
        low.decrementGrade();
    } catch (std::exception& e) {
        //como não pode decrementar a nota do burocrata low, lança uma exceção
        std::cerr << e.what() << "\n";
    }

    std::cout << "Functional decrement:" << std::endl;
    try {
        //tento decrementar a nota do burocrata medium e pode porque a nota dele não é a mais baixa
        medium.decrementGrade();
        std::cout << medium;
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "Functional increment:" << std::endl;
    try {
        //tento incrementar a nota do burocrata medium e pode porque a nota dele não é a mais alta
        medium.incrementGrade();
        std::cout << medium;
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
