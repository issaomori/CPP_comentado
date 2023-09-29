#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::addRange(T begin, T end) {
    //função que adiciona um range de números ao std::vector
    unsigned int space = this->max - this->vect.size();
    //crio uma variável unsigned int chamada space que recebe o valor do atributo max menos o tamanho do std::vector

    if (std::distance(begin, end) > space)
    //se a distância entre o início e o fim do range for maior que o espaço disponível no std::vector
        throw NotEnoughCapacity();
    //lança uma exceção
    while (begin != end) {
    //enquanto o início do range for diferente do fim do range
        this->vect.push_back(*begin);
        //adiciona o valor do início do range ao std::vector
        begin++;
        //incrementa o início do range
    }
}

#endif
