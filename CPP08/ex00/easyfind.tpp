#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

// STL (Standard Template Library) é uma parte fundamental da biblioteca padrão do C++. Ela fornece uma coleção de classes e funções de template que implementam muitos algoritmos e estruturas de dados comuns, como vetores, listas, pilhas, filas, mapas, conjuntos e muito mais.

// Quando o exercício menciona "algoritmo STL", está se referindo aos algoritmos genéricos fornecidos pela STL. Esses algoritmos são funções que operam em contêineres ou sequências de dados, independentemente do tipo de dados contidos neles. Alguns exemplos de algoritmos STL incluem std::sort para ordenação, std::find para busca, std::for_each para aplicar uma função a cada elemento, entre outros.

// Os algoritmos STL são projetados para serem genéricos e reutilizáveis, o que significa que você pode usá-los com uma variedade de tipos de dados e contêineres. Eles são uma parte essencial da programação C++ moderna, pois permitem que você escreva código mais eficiente e legível, evitando a necessidade de reimplementar algoritmos comuns do zero.

// No contexto dos exercícios que você compartilhou, o uso de algoritmos STL é incentivado para realizar operações com contêineres, como encontrar elementos em uma sequência ou ordená-la. Isso é uma prática comum em programação C++ moderna, pois simplifica o código e o torna mais robusto.

//O que é um container? Um container é um objeto que armazena outros objetos e os organiza em uma estrutura de dados. Os containers são usados para gerenciar o armazenamento de seus elementos e facilitar o acesso a eles. Eles controlam a alocação e desalocação de memória dinâmica para seus elementos e fornecem uma interface para acessá-los de maneira uniforme, independentemente do tipo de container.

template <typename T>
// Esta é a definição da função easyfind. Ela toma um tipo T (um container) e um inteiro como argumentos e retorna um iterator para T.
typename T::iterator easyfind(T &container, int i) {
    //método easyfind retorna um iterator para o container T. Ele toma como argumentos um container e um inteiro.
    typename T::iterator iter = std::find(container.begin(), container.end(), i);
    // O método find() da biblioteca algorithm retorna um iterator para o primeiro elemento no range [first, last) que é igual a i. Se nenhum elemento for encontrado, o método retorna o iterator last.

    if (iter == container.end()) {
    // Se o iterator retornado for igual ao iterator last, então o valor não foi encontrado no container. Neste caso, uma exceção do tipo NotFound é lançada.
        throw NotFound();
        //lança uma exceção do tipo NotFound
    }
    return iter;
    //retorna o iterator
}

#endif
