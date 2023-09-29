#include "Zombie.hpp"

int main ( void ){
    
    Zombie *horde;
    //cria um ponteiro para um zombie. Por que eu preciso de um ponteiro? Porque eu vou criar um array de zombies e preciso de um ponteiro para apontar para o primeiro elemento do array.

    std::string N;
    //variável para armazenar o número de zombies que serão criados
    std::string zombie_name;
    //variável para armazenar o nome dos zombies que serão criados

    std::cout << "Insert a number: " << std::endl;
    //imprime na tela para inserir um número
    std::getline(std::cin >> std::ws, N);
    //pega o input do usuário e armazena na variável N(número de zombies que serão criados)
    if (!N.find_first_not_of("0123456789")){
        //verifica se o input do usuário é um número
        std::cout << "Error: Insert a number." << std::endl;
        //imprime na tela que o input do usuário é inválido
        return 0;
        //retorna 0 porque o input do usuário é inválido
    }

    std::cout << "Insert a name: " << std::endl;
    //imprime na tela para inserir um nome
    std::cin >> zombie_name;
    //pega o input do usuário e armazena na variável zombie_name(nome dos zombies que serão criados)

    std::istringstream iss(N);
    //cria um objeto istringstream para converter a string N para um número
    int n;
    //variável para armazenar o número de zombies que serão criados
    iss >> n;
    //converte a string N para um número e armazena na variável n(número de zombies que serão criados)

    horde = zombieHorde(n, zombie_name);
    //cria um array de zombies com o tamanho passado como parâmetro e armazena no ponteiro horde

    for (int i = 0; i < n; i++){
        //enquanto i for menor que o número de zombies passados como parâmetro
        horde[i].announce();
        //faz o zombie gritar brainzzz
    }
    delete [] horde;
    //deleta o array de zombies criado

    return 0;
}
