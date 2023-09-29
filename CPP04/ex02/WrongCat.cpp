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
}

WrongCat &WrongCat::operator=(const WrongCat &name){
    this->type = name.getType();
    std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound(void) const{
    std::cout << "iau iau" << std::endl;
}
