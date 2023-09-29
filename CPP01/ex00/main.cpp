//Neste exercício aprenderemos a utilização de memória alocada em CPP

#include "Zombie.hpp"

int main( void ){
    std::string zombie_name;
    //variável para armazenar o nome do zombie
    
    std::cout << "Enter a name for your zombie(stack): ";
    //imprime na tela para o usuário digitar o nome do zombie
    std::cin >> zombie_name;
    //pega o input do usuário e armazena na variável zombie_name
    Zombie zombie_stack(zombie_name);
    //cria um zombie com o nome passado como parâmetro

    std::cout << "Enter a name for your zombie(heap): ";
    //imprime na tela para o usuário digitar o nome do zombie
    std::cin >> zombie_name;
    //pega o input do usuário e armazena na variável zombie_name
    //são duas maneiras distintas de criar um zombie. Na primeira utiliza o stack e na segunda o heap.
    //O stack é uma memória alocada automaticamente pelo sistema operacional e o heap é uma memória alocada manualmente pelo programador.

    Zombie* zombie_heap = newZombie(zombie_name);
    //cria um zombie com o nome passado como parâmetro
    zombie_heap->announce();
    //faz o zombie gritar brainzzz
    delete zombie_heap;
    //deleta o zombie criado

    std::cout << "Create ramdom name of Zoombie(ramdom): ";
    //imprime na tela para o usuário digitar o nome do zombie
    randomChump("Ronaldo");
    //cria um zombie com o nome passado como parâmetro

    return 0;
}
