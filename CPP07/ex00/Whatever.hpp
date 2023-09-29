#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

//Neste exercício se aprenderá a utilizar os templates, que são uma forma de generalizar o código para que ele possa ser utilizado com diferentes tipos de dados.
//Em que sentido dizemos para generalizar o código? No sentido que criamos uma função que pode ser utilizada com diferentes tipos de dados, sem a necessidade de reescrever o código para cada tipo de dado. Por exemplo crio uma função que soma dois números, mas não quero que ela seja utilizada apenas com inteiros, mas também com floats, doubles, etc. Para isso utilizamos os templates.
//Aqui se implementará uma função swap que troca o conteúdo de duas variáveis do mesmo tipo e duas funções min e max que retornam o menor e o maior valor entre dois valores do mesmo tipo.
template <typename T>
//O template <typename T> indica que a função swap pode ser utilizada com qualquer tipo de dado, e que o tipo de dado será definido no momento em que a função for chamada. Quais são os tipos de dados mais comuns? int, float, double, char, etc.
void swap(T &a, T &b) {
    //Aqui se implementa a função swap que troca o conteúdo de duas variáveis do mesmo tipo.
	T temp;
    //Aqui se cria uma variável temporária do mesmo tipo que as variáveis a e b. Ela é do tipo T, que é o tipo de dado que será definido no momento em que a função for chamada. Se for char o T trocará por char, se for int o T trocará por int, etc.

	temp = a;
    //Aqui se atribui o valor de a para temp.
	a = b;
    //Aqui se atribui o valor de b para a.
	b = temp;
    //Aqui se atribui o valor de temp para b.
}

template <typename T>
//O template <typename T> indica que a função min pode ser utilizada com qualquer tipo de dado, e que o tipo de dado será definido no momento em que a função for chamada. Quais são os tipos de dados mais comuns? int, float, double, char, etc.
//Em qual caso eu utilizo esta função com char? Quando eu quero saber qual é o menor caractere entre dois caracteres. Por exemplo, qual é o menor caractere entre 'a' e 'b'? 'a'.
const T &min(const T &a, const T &b) {
    //Aqui se implementa a função min que retorna o menor valor entre dois valores do mesmo tipo.
    if (a < b) {
        //Aqui se verifica se a é menor que b.
        return a;
        //Se a for menor que b, a função retorna a.
    } else {
        return b;
    }
}

template <typename T>
//O template <typename T> indica que a função max pode ser utilizada com qualquer tipo de dado, e que o tipo de dado será definido no momento em que a função for chamada. Quais são os tipos de dados mais comuns? int, float, double, char, etc.
const T &max(const T &a, const T &b) {
    //Aqui se implementa a função max que retorna o maior valor entre dois valores do mesmo tipo.
    if (a > b) {
        //Aqui se verifica se a é maior que b.
        return a;
    } else {
        return b;
    }
}

#endif
