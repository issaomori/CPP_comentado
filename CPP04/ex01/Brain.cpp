#include "Brain.hpp"

Brain::Brain(void){
    //construtor padrão
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain(void){
    //destrutor padrão
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &name) {
    //construtor de cópia que serve para inicializar um objeto com os valores de outro objeto
    std::cout << "Brain copy constructor called" << std::endl;
    *this = name;
    //chama o operador de atribuição sobrecarregado
}

Brain &Brain::operator=(const Brain &name) {
    //sobrecarga do operador de atribuição que serve para atribuir um objeto a outro
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &name) {
    //verifica se o objeto passado como parâmetro é o mesmo que o objeto que chamou a função
        for (int i = 0; i < 100; ++i) {
        //enquanto i for menor que 100, copia as ideias do objeto passado como parâmetro para o objeto que chamou a função
            this->ideas[i] = name.ideas[i];
            //copia as ideias
        }
    }
    return *this;
    //retorna o objeto que chamou a função
}

void Brain::setIdea(std::string idea, int i){
    //método que serve para atribuir uma ideia a um índice do array de ideias
    this->ideas[i] = idea;
    //atribui a ideia ao índice i do array de ideias
}

std::string Brain::getIdea(int i) const {
    //método que serve para retornar uma ideia de um índice do array de ideias
    return this->ideas[i];
    //retorna a ideia do índice i do array de ideias
}