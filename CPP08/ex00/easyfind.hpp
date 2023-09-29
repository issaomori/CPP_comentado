#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
//biblioteca com funcionalidades de container
#include <deque>
//biblioteca com funcionalidades de container
#include <list>
//biblioteca com funcionalidades de container
#include <iostream>
//biblioteca para entrada e saida de dados
#include <algorithm>
//biblioteca para algoritmos
#include <string>
//biblioteca para strings
#include <stdexcept>
//biblioteca para exceções

class NotFound : public std::exception
//classe not found é definida e esta herda da classe exception. Ela é usada para lançar uma exceção personalizada quando não se encontra o valor no container
{
public:
    const char* what() const throw(){
        //o método what() retorna uma string que descreve a exceção
        return "Unfortunately doesn't exist in this container\n";
    }
};

template <typename T>
// Esta é a declaração de um modelo de função chamado easyfind. Ele toma um tipo T (um container) e um inteiro como argumentos e retorna um iterator para T. Esta função será definida no arquivo "easyfind.tpp".
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"
// Esta linha inclui o arquivo "easyfind.tpp", que contém a implementação da função easyfind. Isso é feito para separar a declaração da implementação da função.

#endif
