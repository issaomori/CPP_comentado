#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
//classe Weapon que possui um atributo type e um método setType
    private:
    //variável privada que só pode ser acessada por métodos da classe
        std::string type;
    public:
    //métodos públicos da classe Weapon que podem ser acessados por qualquer classe
        Weapon();
        //construtor da classe Weapon que serve para inicializar a variável de membro da classe
        ~Weapon();
        //destrutor da classe Weapon que serve para destruir o Weapon passado.

        Weapon(std::string str);
        //construtor da classe Weapon que serve para inicializar a variável de membro da classe
        const std::string &getType();
        //método da classe Weapon que serve para retornar o tipo de Weapon
        void setType(std::string newStr);
        //método da classe Weapon que serve para inicializar a variável de membro da classe
};

#endif