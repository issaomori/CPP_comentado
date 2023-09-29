#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    //função para criar vários zombies passados como parâmetro

    if (N <= 0){
        //verifica se o número de zombies passados é maior que 0
        std::cout << "Error: Insert a number more than 0." << std::endl;
        //imprime na tela que o número de zombies passados é inválido
        return NULL;
        //retorna NULL porque o número de zombies passados é inválido

    }

    Zombie* horde = new Zombie[N];
    //cria um array de zombies com o tamanho passado como parâmetro

    for (int i = 0; i < N; i++){
        //enquanto i for menor que o número de zombies passados como parâmetro
        horde[i].setZombieName(name);
        //seta o nome do zombie com o nome passado como parâmetro, o nome é o mesmo para todos os zombies
    }
    return horde;
    //retorna o array de zombies criado
}
