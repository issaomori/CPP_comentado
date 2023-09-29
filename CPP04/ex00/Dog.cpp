#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
    //construtor padrão inicializando a classe Animal com o tipo Dog
    std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::~Dog(void){
    //destrutor padrão
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &name) : Animal("Dog"){
    //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe Animal com o tipo Dog.
    std::cout << "Dog copy Constructor called" << std::endl;
    *this = name;
    //obj1 = obj2;
    //estou chamando o operador de atribuição sobrecarregado
}

Dog &Dog::operator=(Dog const &name){
    //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.
    // sobrecarga de operador -> serve para modificar os valores de um objeto já inicializado, com base em outro.
    this->type = name.getType();
    //estou atribuindo o valor do atributo type do objeto passado como parâmetro ao atributo type do objeto que está chamando o método.
    std::cout << "Dog Copy Assignment Constructor called" << std::endl;
    return *this;
    //estou retornando o objeto que está chamando o método.
}

void Dog::makeSound(void) const{
    //método que faz o som do cachorro
    std::cout << "Au, Sniff, Au" << std::endl;
}