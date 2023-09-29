#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
    //this->type = "WrongAnimal";
    //construtor padrão inicializando a classe Animal com o tipo WrongAnimal
    std::cout << "Default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
    //destrutor padrão
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    //construtor parametrizado que recebe um parâmetro tipo que é o animal e inicializa o objeto com o valor passado.
    std::cout << "Wrong Animal Constructor called for" << type << std::endl;
    this->setType(type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &name){
    //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.
    this->type = name.getType();
    //estou atribuindo o valor do atributo type do objeto passado como parâmetro ao atributo type do objeto que está chamando o método.
    std::cout << "Wrong Animal Copy Assignment Constructor called" << std::endl;
    return *this;
    //estou retornando o objeto que está chamando o método.
}

void WrongAnimal::makeSound(void) const {
    //método que faz o som do animal
    std::cout << "Wrong Animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    //método que pega o valor do atributo type do objeto que está chamando o método.
    return this->type;
    //estou retornando o valor do atributo type do objeto que está chamando o método.
}

void WrongAnimal::setType(std::string type){
    //método que recebe um parâmetro tipo e atribui esse valor ao atributo type do objeto que está chamando o método.
    this->type = type;
    //estou atribuindo o valor do parâmetro tipo ao atributo type do objeto que está chamando o método.
}
