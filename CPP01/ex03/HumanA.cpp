#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon){
    //construtor da classe HumanA que serve para inicializar as variáveis de membro da classe. Inicializo a variável _weapon depois dos : porque ela é uma referência e não pode ser inicializada no corpo do construtor. Isso é uma regra da linguagem.
    this->_name = name;
    //inicializa a variável de membro da classe com o nome passado como parâmetro
}

HumanA::~HumanA( void ){
}
//destrutor da classe HumanA que serve para destruir o HumanA passado.

void HumanA::attack(){
    //método da classe HumanA que serve para fazer o HumanA atacar
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    //imprime na tela o nome do HumanA e o tipo de arma que ele está usando
}
