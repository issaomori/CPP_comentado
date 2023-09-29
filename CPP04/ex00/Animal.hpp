#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    //classe animal
    protected:
    //atributos protegidos. Para que servem os atributos protegidos? Eles são acessíveis apenas para as classes derivadas, ou seja, as classes que herdam da classe base.
        std::string type;

    public:
    //atributos públicos
        Animal(void);
        //construtor padrão que serve para inicializar os atributos da classe
        virtual ~Animal(void);
        //destrutor padrão que serve para desalocar a memória

        Animal(const Animal &name);
        //construtor de cópia que serve para inicializar os atributos da classe com os valores de outra classe
        Animal(std::string const type);
        Animal &operator=(const Animal &name);

        std::string getType(void) const;
        void setType(std::string type);
        virtual void makeSound(void) const;
        //Por que virtual? Porque eu quero que o método seja sobrescrito pelas classes derivadas. Por que eu quero que o método seja sobrescrito pelas classes derivadas? Porque eu quero que o método seja polimórfico. Por que eu quero que o método seja polimórfico? Porque o polimosfismo é uma ferramenta poderosa na programação orientada a objetos, pois permite escrever código mais flexível e genérico. Isso facilita a criação de hierarquias de classes e o uso de interfaces comuns para objetos que compartilham características semelhantes, mas também têm comportamentos específicos. Isso torna o código mais fácil de entender, manter e estender.
};

#endif
