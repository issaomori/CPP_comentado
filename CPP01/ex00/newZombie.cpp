#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    //função para criar um zombie passado como parâmetro
    Zombie* zombie = new Zombie(name);
    //cria um zombie com o nome passado como parâmetro
    return zombie;
    //retorna o zombie criado
}
