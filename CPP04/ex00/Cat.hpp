#ifndef CAT_HPP
#define CAT_HPP

// #include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
    //classe Cat que herda da classe Animal
    public:
    //construtor parametrizado -> serve para inicializar um objeto com os valores passados.
        Cat(void);
        //construtor padrão inicializando a classe Animal com o tipo Cat
        ~Cat(void);
        //destrutor padrão
        
        Cat(Cat const &name);
        //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe Animal com o tipo Cat.
        Cat &operator=(Cat const &name);
        //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.

        void makeSound(void) const;
        //método que faz o som do gato
};

#endif
