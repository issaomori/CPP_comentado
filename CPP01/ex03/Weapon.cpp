#include "Weapon.hpp"

Weapon::Weapon(){
}
//construtor da classe Weapon que serve para inicializar a variável de membro da classe

Weapon::Weapon(std::string _private_str){
    //construtor da classe Weapon que serve para inicializar a variável de membro da classe
    this->setType(_private_str);
    //inicializa a variável de membro da classe com o nome passado como parâmetro. Uso o this-> para acessar o método da classe e não ter chance de conflito com o parâmetro passado.
}

Weapon::~Weapon( void ){
}
//destrutor da classe Weapon que serve para destruir o Weapon passado.

const std::string &Weapon::getType( void ){
    //método da classe Weapon que serve para retornar o tipo de Weapon(arma do Human)
    return (this->type);
    //retorna o tipo de Weapon
}

void Weapon::setType(std::string newStr){
    //método da classe Weapon que serve para inicializar a variável de membro da classe. Basicamente, serve para trocar o tipo de Weapon(arma do Human).
    this->type = newStr;
    //inicializa a variável de membro da classe com o nome passado como parâmetro. Uso o this-> para acessar o método da classe e não ter chance de conflito com o parâmetro passado.
}
