#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    //classe WrongAnimal
    protected:
        //atributo protegido -> só pode ser acessado pela própria classe e pelas classes que herdam dela.
        std::string type;
        //atributo tipo string
    
    public:
    //construtor parametrizado -> serve para inicializar um objeto com os valores passados.
        WrongAnimal(void);
        //construtor padrão inicializando o atributo type
        ~WrongAnimal(void);
        //destrutor padrão

        WrongAnimal(std::string type);
        //construtor parametrizado que recebe um parâmetro tipo que é o animal e inicializa o objeto com o valor passado.
        WrongAnimal(const WrongAnimal &name);
        //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado.
        WrongAnimal &operator=(const WrongAnimal &name);
        //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.

        std::string getType(void) const;
        //método que retorna o tipo do animal
        void setType(std::string type);
        //método que recebe um parâmetro tipo e atribui esse valor ao atributo type do objeto que está chamando o método.
        
        void makeSound(void) const;
        //método que faz o som do animal

};
#endif