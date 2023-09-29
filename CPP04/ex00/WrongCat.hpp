#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat(void);
        //construtor padrão inicializando a classe WrongAnimal com o tipo WrongCat
        ~WrongCat(void);
        //destrutor padrão

        WrongCat(const WrongCat &name);
        //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe WrongAnimal com o tipo WrongCat.
        WrongCat &operator=(const WrongCat &name);
        //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.

        void makeSound(void) const;
        //método que faz o som do gato
};

#endif