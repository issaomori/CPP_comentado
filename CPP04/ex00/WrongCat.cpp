#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
    //construtor padrão inicializando a classe Animal com o tipo WrongCat
    std::cout << "Default WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
    //destrutor padrão
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &name) : WrongAnimal("WrongCat"){
    //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado e inicializa a classe Animal com o tipo WrongCat.
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = name;
    //obj1 = obj2;
    //estou chamando o operador de atribuição sobrecarregado
}

WrongCat &WrongCat::operator=(const WrongCat &name){
    //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.
    this->type = name.getType();
    //estou atribuindo o valor do atributo type do objeto passado como parâmetro ao atributo type do objeto que está chamando o método.
    std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
    return *this;
    //estou retornando o objeto que está chamando o método.
}

void WrongCat::makeSound(void) const{
    //método que faz o som do gato
    std::cout << "iau iau" << std::endl;
}
