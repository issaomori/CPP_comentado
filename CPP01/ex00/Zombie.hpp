#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
//classe Zombie que possui um atributo name e um método announce
{
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

        Zombie(std::string name);
        //construtor da classe Zombie que serve para inicializar a variável de membro da classe
        void announce();
        //método da classe Zombie que serve para fazer o zombie gritar brainzzz
};

Zombie* newZombie( std::string name );
//método da classe Zombie que serve para criar um novo zombie
void randomChump( std::string name );
//método da classe Zombie que serve para criar um zombie aleatório passado como parâmetro

#endif
