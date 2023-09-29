#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
//biblioteca padrão de entrada e saída de dados
#include <sstream>
#include <string>

class Zombie{
    //classe Zombie que possui um atributo name e um método announce
    private:
    //variável privada que só pode ser acessada por métodos da classe
        std::string _name;
        //variável de membro da classe Zombie que armazena o nome do Zombie
    public:
    //métodos públicos da classe Zombie que podem ser acessados por qualquer classe
        Zombie();
        //construtor da classe Zombie que serve para inicializar a variável de membro da classe
        ~Zombie();
        //destrutor da classe Zombie que serve para destruir o zombie passado.

        void announce();
        //método da classe Zombie que serve para fazer o zombie gritar brainzzz
        void setZombieName(std::string name);
        //método da classe Zombie que serve para inicializar a variável de membro da classe

};

Zombie* zombieHorde( int N, std::string name );
//método da classe Zombie que serve para criar vários zombies.

#endif
