#include "Animal.hpp"


// construtor parametrizado -> serve para inicializar um objeto com os valores passados.
// construtor de cópia -> serve para tbm inicializar um objeto, copiando de outro.
// por exemplo:
// 	objeto a já existe
// 	objeto new b(a)
// ao utilizar o construtor de cópia o b terá os valores de a.

// sobrecarga de operador -> serve para modificar os valores de um objeto já inicializado, com base em outro.


// java
// js
// python
// go
Animal::Animal(void) : type("Animal"){
    //construtor padrão inicializando o atributo type
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal(void){
    //destrutor padrão
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &name){
    //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado.
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = name;
    //estou chamando o operador de atribuição sobrecarregado
    //O this está se referenciando e no caso é um objeto e está recebendo um outro objeto que é passado como parâmetro.
}

Animal::Animal(std::string const type){
    //construtor parametrizado que recebe um parâmetro tipo que é o animal e inicializa o objeto com o valor passado.
    std::cout << "Animal Constructor called " << type << std::endl;
    this->setType(type);
    //estou chamando o método setType que recebe um parâmetro tipo e atribui esse valor ao atributo type do objeto.
}

Animal &Animal::operator=(const Animal &name){
    //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.
    // sobrecarga de operador -> serve para modificar os valores de um objeto já inicializado, com base em outro.
    this->type = name.getType();
    //estou atribuindo o valor do atributo type do objeto passado como parâmetro ao atributo type do objeto que está chamando o método.
    std::cout << "Animal Copy Assignment Constructor called" << std::endl;
    return *this;
    //estou retornando o objeto que está chamando o método.
}

std::string Animal::getType(void) const {
    //método que pega o valor do atributo type do objeto que está chamando o método.
    return this->type;
    //estou retornando o valor do atributo type do objeto que está chamando o método.
}

void Animal::setType(std::string type){
    //método que recebe um parâmetro tipo e atribui esse valor ao atributo type do objeto que está chamando o método.
    this->type = type;
    //estou atribuindo o valor do parâmetro tipo ao atributo type do objeto que está chamando o método.
}

void Animal::makeSound(void) const{
    //método que emite um som.
    std::cout << "Sound Emitted by the Animal" << std::endl;
    //estou imprimindo uma mensagem na tela.
}