#include "Harl.hpp"

Harl::Harl(){
    //construtor da classe Harl que serve para inicializar a variável de membro da classe
    level_functions ["DEBUG"] = &Harl::debug;
    //inicializa a variável de membro da classe com o nome passado com debug
    level_functions ["INFO"] = &Harl::info;
    //inicializa a variável de membro da classe com o nome passado com info
    level_functions ["WARNING"] = &Harl::warning;
    //inicializa a variável de membro da classe com o nome passado com warning
    level_functions ["ERROR"] = &Harl::error;
    //inicializa a variável de membro da classe com o nome passado com error
    }

Harl::~Harl(){
}
//destrutor da classe Harl que serve para destruir o Harl passado.

void Harl::complain(std::string level){
    //método da classe Harl que serve para fazer o Harl reclamar
    std::map<std::string, LevelFunction>::iterator it = level_functions.find(level);
    //cria um iterador para o mapa de dados que armazena strings e ponteiros para métodos da classe Harl e procura o level passado como parâmetro
    if (it != level_functions.end())
    //se o level passado como parâmetro for encontrado
        (this->*(it->second))();
        //chama o método da classe Harl que está armazenado no mapa de dados
}

void Harl::debug( void ){
    //método da classe Harl que serve para fazer o Harl debugar
    std::cout << "DEBUG: " << std::endl;
    //imprime na tela que o Harl está debugando
    std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    //imprime na tela que o Harl ama bacon
}

void Harl::info( void ){
    //método da classe Harl que serve para fazer o Harl informar
    std::cout << "INFO: " << std::endl;
    //imprime na tela que o Harl está informando
    std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
    //imprime na tela que o Harl quer mais bacon
}

void Harl::warning( void ){
    //método da classe Harl que serve para fazer o Harl avisar
    std::cout << "WARNING: " << std::endl;
    //imprime na tela que o Harl está avisando
    std::cout << " I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month.." << std::endl;
    //imprime na tela que o Harl merece bacon de graça
}

void Harl::error( void ){
    //método da classe Harl que serve para fazer o Harl mostrar um erro
    std::cout << "ERROR: " << std::endl;
    //imprime na tela que o Harl está mostrando um erro
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    //imprime na tela que o Harl quer falar com o gerente
}
