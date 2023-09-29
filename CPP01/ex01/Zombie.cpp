#include "Zombie.hpp"

Zombie::Zombie( void ){
}
//construtor da classe Zombie que serve para inicializar a variável de membro da classe

void Zombie::setZombieName(std::string name){
    //método da classe Zombie que serve para inicializar a variável de membro da classe
    this->_name = name;
    //inicializa a variável de membro da classe com o nome passado como parâmetro
    std::cout << "Zombie created" << std::endl;
    //imprime na tela que o zombie foi criado
}

Zombie::~Zombie( void ){
    //destrutor da classe Zombie que serve para destruir o zombie passado.
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void Zombie::announce( void ){
    //método da classe Zombie que serve para fazer o zombie gritar brainzzz
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
