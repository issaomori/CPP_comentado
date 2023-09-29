#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
    //construtor padrão inicializando a classe Animal com o tipo Cat
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::~Cat(void){
    //destrutor padrão
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &name) : Animal("Cat"){
    //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe Animal com o tipo Cat.
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = name;
    // obj1 = obj2;
    //estou chamando o operador de atribuição sobrecarregado
}

Cat &Cat::operator=(const Cat &name){
    //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.
    // sobrecarga de operador -> serve para modificar os valores de um objeto já inicializado, com base em outro.
    this->type = name.getType();
    //estou atribuindo o valor do atributo type do objeto passado como parâmetro ao atributo type do objeto que está chamando o método.
    std::cout << "Cat Copy Assignment Operator called" << std::endl;
    return *this;
    //estou retornando o objeto que está chamando o método.
}

void Cat::makeSound(void) const{
    //método que faz o som do gato
    std::cout <<"Meow" << std::endl;
}
