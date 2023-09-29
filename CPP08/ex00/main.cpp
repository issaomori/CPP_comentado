#include "easyfind.hpp"

//Este exercício serve para dar a introdução ao uso de containers.
//O que são containers? Containers são objetos que armazenam outros objetos. Eles são usados para gerenciar coleções de objetos de um determinado tipo. A biblioteca padrão do C++ fornece uma série de containers que podem ser usados para armazenar diferentes tipos de dados. Alguns exemplos de containers são std::vector, std::list, std::map, std::set, std::queue e std::stack.
//Como assim armazenar outros objetos? Por exemplo, um std::vector<int> é um container que armazena inteiros. Um std::vector<std::string> é um container que armazena strings. Um std::list<double> é um container que armazena números de ponto flutuante. E assim por diante.
//Quais são as principais vantagens de usar containers? Os containers fornecem uma maneira conveniente de armazenar e acessar dados. Eles são muito úteis para armazenar coleções de dados que podem ser acessados ​​de forma eficiente. Por exemplo, um std::vector é um container que armazena seus elementos em uma matriz contígua de memória, o que permite um acesso rápido aos elementos. Um std::list é um container que armazena seus elementos em uma lista duplamente encadeada, o que permite a inserção e remoção eficientes de elementos em qualquer posição da lista.
//Me dê um exemplo de matriz contígua de memória. Uma matriz contígua de memória é uma matriz de elementos que são armazenados em posições de memória adjacentes. Por exemplo, se você tiver um std::vector<int> com 10 elementos, os elementos serão armazenados em posições de memória adjacentes, como mostrado abaixo:
// 0 1 2 3 4 5 6 7 8 9
// Uso de containers: Mostra como criar e preencher containers como std::vector e std::list com elementos.

// Templates: Apresenta o uso de templates para criar uma função genérica easyfind que pode ser usada com diferentes tipos de containers.

// Manipulação de exceções: Demonstra como lidar com exceções personalizadas (no caso, a classe NotFound) que podem ocorrer quando um elemento não é encontrado no container.

// Algoritmos da STL: Utiliza a função std::find da STL para buscar elementos em containers.

// Em resumo, este código serve como uma introdução prática ao uso de containers, templates e tratamento de exceções em C++, ajudando a entender como esses conceitos são aplicados em situações reais de programação. É um bom ponto de partida para quem está aprendendo sobre containers e programação genérica em C++.
int main(void) {
    std::cout << " ---------- TEST VECTOR ---------- " << std::endl;

    std::vector<int> v_test;
    //crio um objeto da classe vector que armazena inteiros

    for (int i = 0; i < 10; i++) {
        //preencho o vector com os valores de 1 a 10
        v_test.insert(v_test.begin(), i + 1);
        //o método insert() insere um elemento no vector. Ele toma como argumentos um iterator para a posição onde o elemento será inserido e o elemento a ser inserido.
        //o método begin() retorna um iterator para o primeiro elemento do vector
    }
    std::cout << std::endl;

    std::cout << "1. Test valid numbers: " << std::endl;

    std::vector<int>::iterator it1 = easyfind(v_test, 1);
    //crio um iterator para o vector e chamo a função easyfind() passando como argumentos o vector e o valor a ser encontrado
    //Chama a função easyfind para procurar o número 1 no std::vector v_test e armazena o resultado em it1, que é um iterator.
    std::cout << "Number found in vector: " << *it1 << std::endl;

    it1 = easyfind(v_test, 10);
    //Chama a função easyfind para procurar o número 10 no std::vector v_test e armazena o resultado em it1, que é um iterator.
    std::cout << "Number found in vector: " << *it1 << std::endl;
    //imprime o valor encontrado
    std::cout << std::endl;

    std::cout << "2. Test invalid numbers: " << std::endl;
    try {
        //Tenta encontrar o número 11 no std::vector e, se não encontrar, captura e lida com a exceção NotFound que é lançada, imprimindo a mensagem de erro.
        std::vector<int>::iterator it1 = easyfind(v_test, 11);
        std::cout << *it1 << std::endl;
    } catch (const std::exception& e) {
        //como não existe o número 11 no vector, a exceção NotFound é lançada e capturada pelo catch
        std::cerr << e.what();
    }

    try {
        //Tenta encontrar o número -1 no std::vector e, se não encontrar, captura e lida com a exceção NotFound que é lançada, imprimindo a mensagem de erro.
        std::vector<int>::iterator it1 = easyfind(v_test, -1);
        std::cout << *it1 << std::endl;
    } catch (const std::exception& e) {
        //como não existe o número -1 no vector, a exceção NotFound é lançada e capturada pelo catch
        std::cerr << e.what();
    }
    std::cout << std::endl;

    std::cout << " ----------- TEST LIST ----------- " << std::endl;

    std::list<int> l_test;
    // Cria um objeto std::list chamado l_test que armazenará inteiros.

    for (int i = 0; i < 10; i++) {
        //Preenche a std::list l_test com números de 1 a 10, inserindo-os no início da lista.
        l_test.insert(l_test.begin(), i + 1);
    }
    std::cout << std::endl;

    std::cout << "3. Test valid numbers: " << std::endl;

    std::list<int>::iterator it2 = easyfind(l_test, 1);
    //Chama a função easyfind para procurar o número 1 na std::list l_test e armazena o resultado em it2, que é um iterator.
    std::cout << "Number found in list: " << *it2 << std::endl;

    it2 = easyfind(l_test, 10);
    //Chama a função easyfind para procurar o número 10 na std::list l_test e armazena o resultado em it2, que é um iterator.
    std::cout << "Number found in list: " << *it2 << std::endl;
    //imprime o valor encontrado
    std::cout << std::endl;

    std::cout << "4. Test invalid numbers: " << std::endl;

    try {
        //Tenta encontrar o número 11 na std::list e, se não encontrar, captura e lida com a exceção NotFound que é lançada, imprimindo a mensagem de erro.
        std::list<int>::iterator it2 = easyfind(l_test, 11);
        std::cout << *it2 << std::endl;
    } catch (const std::exception& e) {
        //como não existe o número 11 na lista, a exceção NotFound é lançada e capturada pelo catch
        std::cerr << e.what();
    }

    try {
        std::list<int>::iterator it2 = easyfind(l_test, -1);
        //Tenta encontrar o número -1 na std::list e, se não encontrar, captura e lida com a exceção NotFound que é lançada, imprimindo a mensagem de erro.
        std::cout << *it2 << std::endl;
    } catch (const std::exception& e) {
        //como não existe o número -1 na lista, a exceção NotFound é lançada e capturada pelo catch
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
