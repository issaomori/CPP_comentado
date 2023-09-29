#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
//template para que a função possa receber qualquer tipo de dado
void iter(T* array, size_t len, void (*fptr)(T& elem)) {
    //função iter que recebe um array, o tamanho do array e um ponteiro para uma função. Para que serve a função iter? Para aplicar a função fptr a cada elemento do array. Exemplo: se fptr for a função printElem, a função iter vai imprimir cada elemento do array.
    if (!array || len <= 0)
    //se o array for nulo ou o tamanho do array for menor ou igual a 0, retorna
        return;
    for (size_t i = 0; i < len; i++)
    //percorre o array
        fptr(array[i]);
    //aplica a função fptr a cada elemento do array
}

template<typename T>
//template para que a função possa receber qualquer tipo de dado
void iter(T const* array, size_t len, void (*fptr)(T const& elem)) {
    //Por que eu crio 2 funções iter? Porque eu quero que a função iter possa receber um array constante. Se eu não criar uma função iter para um array constante, a função iter não vai conseguir receber um array constante. Exemplo: se fptr for a função printElem, a função iter vai imprimir cada elemento do array.
    if (!array || len <= 0)
    //se o array for nulo ou o tamanho do array for menor ou igual a 0,
        return;
    for (size_t i = 0; i < len; i++)
    //percorre o array
        fptr(array[i]);
    //aplica a função fptr a cada elemento do array
}

template<typename T>
void printElem(T& elem) {
    //função printElem que recebe um elemento do tipo T e imprime esse elemento
    std::cout << elem << " ";
    //imprime o elemento
}


template<typename T>
void printElem(T const& elem) {
    //função printElem que recebe um elemento do tipo T constante e imprime esse elemento
    std::cout << elem << " ";
    //imprime o elemento
}

template<typename T>
void printElemLn(T& elem) {
    //função printElemLn que recebe um elemento do tipo T e imprime esse elemento com uma quebra de linha
    std::cout << elem << std::endl;
}

template<typename T>
void printElemLn(T const& elem) {
    //função printElemLn que recebe um elemento do tipo T constante e imprime esse elemento com uma quebra de linha
    std::cout << elem << std::endl;
}

template<typename T>
void addOne(T& elem) {
    //função addOne que recebe um elemento do tipo T e incrementa esse elemento
    elem++;
}

template<typename T>
void reduceOne(T& elem) {
    //função reduceOne que recebe um elemento do tipo T e decrementa esse elemento
    elem--;
}

#endif
