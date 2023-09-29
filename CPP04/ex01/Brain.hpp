#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    //classe Brain
    private:
    //atributos privados que apenas a classe pode acessar
        std::string ideas[100];
        //array de 100 strings que serve para armazenar as ideias do cérebro do animal
    
    public:
        Brain(void);
        //construtor padrão
        ~Brain(void);
        //destrutor padrão
    
        Brain(Brain const &name);
        //construtor de cópia que serve para inicializar um objeto com os valores de outro objeto
        Brain &operator=(Brain const &name);
        //sobrecarga do operador de atribuição que serve para atribuir um objeto a outro

        void setIdea(std::string idea, int i);
        //método que serve para atribuir uma ideia a um índice do array de ideias
        std::string getIdea(int i) const;
        //método que serve para retornar uma ideia de um índice do array de ideias
};

#endif
