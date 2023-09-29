#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
//classe HumanB que possui um atributo name e um método attack
    private:
    //variável privada que só pode ser acessada por métodos da classe
        std::string _name;
        //variável de membro da classe HumanB que armazena o nome do HumanB
        Weapon *_weapon;
        //variável de membro da classe HumanB que armazena o tipo de arma do HumanB e tem um ponteiro para Weapon porque é uma referência
        
    public:
        HumanB();
        //construtor da classe HumanB que serve para inicializar a variável de membro da classe
        ~HumanB();
        //destrutor da classe HumanB que serve para destruir o HumanB passado.
    
        HumanB(std::string name);
        //construtor da classe HumanB que serve para inicializar a variável de membro da classe
        void attack(void);
        //método da classe HumanB que serve para fazer o HumanB atacar
        void setWeapon(Weapon &weapon);
        //método da classe HumanB que serve para inicializar a variável de membro da classe
};

#endif
