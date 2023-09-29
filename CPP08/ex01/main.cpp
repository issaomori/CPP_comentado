#include "Span.hpp"
#include <iostream>

int main() {
    try {
        Span sp = Span(5);
        //tenta criar um objeto da classe Span com capacidade 5

        // adciono números ao std::vector
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        const std::vector<int>& vect = sp.getVect();
        //crio um objeto constante da classe vector que armazena inteiros e recebe o valor do atributo vect do objeto sp
        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vect.size(); ++i) {
            //enquanto i for menor que o tamanho do objeto vect, isso serve para percorrer o objeto vect e imprimir os valores
            std::cout << vect[i] << " ";
            //imprime o valor do elemento i do objeto vect
        }
        std::cout << std::endl;

        std::cout << "---------------------------------------------- " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        //imprime o menor intervalo entre dois números do std::vector
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "---------------------------------------------- " << std::endl;
        //imprime o maior intervalo entre dois números do std::vector

    } catch (const std::exception& e) {
        //se ocorrer uma exceção
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span sp2 = Span(3);
        //tenta criar um objeto da classe Span com capacidade 3

        int arr[] = { 1, 5, 2 };
        //adiciona um array de inteiros
        sp2.addRange(arr, arr + sizeof(arr) / sizeof(arr[0]));
        //adciono um range de números ao std::vector que vai do início do array até o final do array e é dividido pelo tamanho de um elemento do array

        // Display the vector contents
        const std::vector<int>& vect2 = sp2.getVect();
        //crio um objeto constante da classe vector que armazena inteiros e recebe o valor do atributo vect do objeto sp2
        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vect2.size(); ++i) {
            //enquanto i for menor que o tamanho do objeto vect2, isso serve para percorrer o objeto vect2 e imprimir os valores
            std::cout << vect2[i] << " ";
            //imprime o valor do elemento i do objeto vect2
        }
        std::cout << std::endl;

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        //imprime o menor intervalo entre dois números do std::vector
        std::cout << "---------------------------------------------- " << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        //imprime o maior intervalo entre dois números do std::vector
        std::cout << "---------------------------------------------- " << std::endl;

    } catch (const std::exception& e) {
        //se ocorrer uma exceção
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
