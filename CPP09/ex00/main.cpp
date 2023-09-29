#include "BitCoinExchange.hpp"

//O intuito desse exercício é por na prática o que foi aprendido sobre containers e escolher o melhor container para cada situação. Neste primeiro exercício, utilizei o container map porque ele serve para armazenar pares de chave-valor, e a chave é única, então é perfeito para armazenar as datas e o valor do bitcoin naquela data, é ordenado, então é possível ordenar as datas em ordem crescente, é uma boa escolha porque é possível acessar os valores através da chave, então é possível acessar o valor do bitcoin em uma data específica, é uma boa escolha porque é possível inserir novos valores no meio do container, sem ter que reordenar o container inteiro e é possível remover valores do meio do container sem ter que reordenar o container inteiro.

int main(int argc, char **argv)
{
    BitcoinExchange exchange;
    //declaro a classe BitcoinExchange
    (void)argv;
    //declaro o argv void para não dar warning
    if (argc != 2)
    //se o argc for diferente de 2, ou seja, se o usuário não passar o nome do arquivo, imprimo a mensagem de erro
    {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
        //retorno 1 para indicar que houve um erro
    }

    exchange.LoadData();
    //chamo a função LoadData da classe BitcoinExchange
    exchange.InputHandler(argv[1]);
    //chamo a função InputHandler da classe BitcoinExchange
    return 0;
    //retorno 0 para indicar que não houve erro
}