#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    //classe Dog que herda da classe Animal
    public:
    //construtor parametrizado -> serve para inicializar um objeto com os valores passados.
        Dog(void);
        //construtor padrão inicializando a classe Animal com o tipo Dog
        ~Dog(void);
        //destrutor padrão

        Dog(Dog const &name);
        //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe Animal com o tipo Dog.
        Dog &operator=(Dog const &name);
        //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.

        void makeSound(void) const;
        //método que faz o som do cachorro
};
#endif