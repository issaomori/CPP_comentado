


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
    //classe Burocrata
    private:
    //atributos privados que só podem ser acessados por metodos publicos da classe
        const std::string name;
        //constante string name que não pode ser alterada
        int grade;
        //int grade(valor) que pode ser alterado


    public:
    //metodos publicos que podem ser acessados por qualquer classe
        Bureaucrat();
        //construtor padrão
        ~Bureaucrat();
        //destrutor
        Bureaucrat(const std::string name, int grade);
        //construtor parametrizado que serve para inicializar os atributos da classe
        Bureaucrat(const Bureaucrat &copy);
        //construtor de copia que serve para inicializar os atributos da classe com os atributos de outra classe
        Bureaucrat &operator=(const Bureaucrat &rhs);
        //sobrecarga do operador de atribuição '=' para atribuir um objeto a outro

        std::string getName() const;
        //metodo que retorna o nome do burocrata
        int getGrade() const;
        //metodo que retorna a nota do burocrata

        int incrementGrade();
        //metodo que incrementa a nota do burocrata
        int decrementGrade();
        //metodo que decrementa a nota do burocrata

    class GradeTooHighException : public std::exception{
        //a classe GradeTooHighException é uma classe que herda da classe exception
        //A classe exception é uma classe existente no cpp e ela serve para criar exceções personalizadas
        //e fornece um metodo chamado what() que retorna uma string que descreve o erro, isso serve para
        //projetar hierarquia de exceções.
        public:
        //metodos publicos que podem ser acessados por qualquer classe
            virtual const char *what() const throw();
            //método que retorna uma string que descreve o erro
            //Uso o virtual para que o metodo seja sobrescrito por uma classe derivada
            //Uso o const para que o metodo não altere nenhum atributo da classe
            //O what() é um metodo que retorna uma string que descreve o erro
            //Uso o throw para que o metodo não lance nenhuma exceção
            //Por que o throw não lança nenhuma exceção, se eu quero lançar uma exceção?
            //Porque não é aqui que eu defino se lança ou não exceção, basicamente, serve para
            //indicar que ao lançar uma exceção, virá uma string que descreve o erro junto, caso eu queira.
    };
    
    class GradeTooLowException : public std::exception{
        //mesma coisa da classe GradeTooHighException
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
//sobrecarga do operador de inserção '<<' para inserir um objeto da classe Bureaucrat em um stream de saida.
//Por que está fora da classe? Porque o operador de inserção é um operador binario, ou seja, ele precisa de dois operandos
//O que é um operador binario? É um operador que precisa de dois operandos para funcionar
//O que são operandos? São os objetos que estão sendo operados, no caso, o stream de saida e o objeto da classe Bureaucrat
//O que é stream de saida? É um fluxo de saida, ou seja, é um fluxo de dados que vai para a saida padrão, no caso, o terminal

#endif
