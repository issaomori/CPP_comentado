#include "HumanB.hpp"

HumanB::HumanB( void ){
}
//construtor da classe HumanB que serve para inicializar a variável de membro da classe

HumanB::HumanB(std::string name){
    //construtor da classe HumanB que serve para inicializar a variável de membro da classe
    this->_name = name;
    //inicializa a variável de membro da classe com o nome passado como parâmetro
    this->_weapon = NULL;
    //inicializa a variável de membro da classe com NULL, ou seja, sem arma
}

HumanB::~HumanB( void ){
}
//destrutor da classe HumanB que serve para destruir o HumanB passado.

void HumanB::attack( void ){
    //método da classe HumanB que serve para fazer o HumanB atacar
    if (!this->_weapon){
        //se o tipo de arma for NULL, ou seja, se o HumanB não tiver arma
        std::cout << "HumanB hasn't weapon." << std::endl;
        //imprime na tela que o HumanB não tem arma
        return;
    }
    std::cout << this->_name << " attacks with their weapon " << this->_weapon->getType() << std::endl;
    //imprime na tela o nome do HumanB e o tipo de arma que ele está usando
}

void HumanB::setWeapon(Weapon &weapon){
    //método da classe HumanB que serve para inicializar a variável de membro da classe. Basicamente, serve para trocar o tipo de Weapon(arma do Human).
    this->_weapon = &weapon;
    //inicializa a variável de membro da classe com o nome passado como parâmetro. Uso o this-> para acessar o método da classe e não ter chance de conflito com o parâmetro passado.
}
