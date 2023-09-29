#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
//Neste ultimo exercício basicamente iremos utilizar os templates com classes. Quais são as vantagens de utilizar os templates nas classes? A principal vantagem é que podemos criar uma classe que pode receber qualquer tipo de dado. Como anteriormente que eu criava a função e ela se adaptava a partir do dado passado na main, o mesmo ocorrerá aqui.
class Array {
    //crio uma classe Array
private:
//atributos privados da classe que só podem ser acessados por metodos da classe
    unsigned int _size;
    //variavel privada _size do tipo unsigned int
    T *ptr;
    //variavel privada ptr do tipo T

public:
    class InvalidIndex : public std::exception {
        //crio uma classe InvalidIndex que herda da classe exception
    public:
    //metodos publicos da classe que podem ser acessados por outras classes
        const char* what() const throw() {
            //metodo what que retorna uma mensagem de erro para lançar uma exceção.
            return "Index is out of range";
            //retorna a string "Index is out of range"
        }
    };

    Array() : _size(0), ptr(NULL) {}
    //construtor padrão inicializa _size com 0 e ptr com NULL

    Array(unsigned int size) : _size(size), ptr(new T[size]) {}
    //construtor parametrizado inicializa _size com size e ptr com um array de tamanho size

    Array(const Array &src) : _size(src._size), ptr(new T[src._size]) {
        //construtor de cópia inicializa _size com src._size e ptr com um array de tamanho src._size
        for (unsigned int i = 0; i < _size; i++) {
            //percorre o array até o tamanho de _size
            ptr[i] = src[i];
            //atribui o valor de src[i] para ptr[i]
        }
    }

    ~Array() {
        //destrutor padrão
        delete[] ptr;
        //desaloca o array ptr
    }

    Array &operator=(const Array &src) {
        //sobrecarga do operador de atribuição para poder atribuir um array a outro
        if (this != &src) {
            //se o array não for igual ao array src
            delete[] ptr;
            //desaloca o array ptr
            _size = src._size;
            //atribui o valor de src._size para _size
            ptr = new T[_size];
            //aloca um novo array de tamanho _size para ptr
            for (unsigned int i = 0; i < _size; i++) {
                //percorre o array até o tamanho de _size
                ptr[i] = src[i];
                //atribui o valor de src[i] para ptr[i]
            }
        }
        return *this;
        //retorna o array
    }

    T &operator[](unsigned int i) {
        //sobrecarga do operador [] para poder acessar um elemento do array. Esse operador serve para acessar um elemento do array e também para atribuir um valor a um elemento do array.
        if (i >= _size) {
            //se i for maior ou igual a _size
            throw InvalidIndex();
            //lança uma exceção
        }
        return ptr[i];
        //retorna o elemento do array
    }

    const T &operator[](unsigned int i) const {
        //sobrecarga do operador [] para poder acessar um elemento do array. Esse operador serve para acessar um elemento do array. Mas agora o array é constante, ou seja, não podemos atribuir um valor a um elemento do array.
        if (i >= _size) {
            //se i for maior ou igual a _size
            throw InvalidIndex();
            //lança uma exceção
        }
        return ptr[i];
        //retorna o elemento do array
    }

    unsigned int size() const {
        //metodo que retorna o tamanho do array
        return _size;
        //retorna o tamanho do array
    }
};

#endif
