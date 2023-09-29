#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;
//declaração antecipada da classe Bureaucrat para que o compilador saiba que ela existe

class Form{
    //classe Form
    private:
    //atributos privados que só podem ser acessados por metodos publicos da classe
        const std::string _name;
        //constante string name que não pode ser alterada
        bool _isSigned;
        //bool isSigned(valor) que pode ser alterado
        const int _gradeToSign;
        //constante int gradeToSign(valor) que não pode ser alterada
        const int _gradeToExec;
        //constante int gradeToExec(valor) que não pode ser alterada
    public:
        Form();
        //construtor padrão
        ~Form();
        //destrutor

        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        //construtor parametrizado que serve para inicializar os atributos da classe
        Form(const Form &rhs);
        //construtor de copia que serve para inicializar os atributos da classe com os atributos de outra classe

        Form &operator=(const Form &rhs);
        //sobrecarga do operador de atribuição '=' para atribuir um objeto a outro

        std::string getName() const;
        //metodo que retorna o nome do formulario
        bool isSigned() const;
        //metodo que retorna se o formulario está assinado ou não
        int gradeToSign() const;
        //metodo que retorna a nota necessaria para assinar o formulario
        int gradeToExec() const;
        //metodo que retorna a nota necessaria para executar o formulario

        void beSigned(const Bureaucrat &bureaucrat);
        //metodo que assina o formulario

        class GradeTooHighException : public std::exception{
            //a classe GradeTooHighException é uma classe que herda da classe exception
        public:
            virtual const char *what() const throw();
            //método que retorna uma string que descreve o erro
        };
    
        class GradeTooLowException : public std::exception{
            //a classe GradeTooLowException é uma classe que herda da classe exception
        public:
            virtual const char *what() const throw();
            //método que retorna uma string que descreve o erro
        };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);
//sobrecarga do operador de inserção '<<' para imprimir um objeto da classe Form

#endif
