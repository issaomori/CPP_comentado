#include "Zombie.hpp"

void randomChump( std::string name ){
    //função para criar um zombie aleatório passado como parâmetro
    Zombie zombie(name);
    //cria um zombie com o nome passado como parâmetro
    zombie.announce();
    //faz o zombie gritar brainzzz
}
