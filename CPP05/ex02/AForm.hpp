#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
//declaração antecipada da classe Bureaucrat para que o compilador saiba que ela existe

class AForm{
    //classe AForm
    
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
        
    protected:
        const std::string _target;
        //constante string target que não pode ser alterada
        //O alvo serve para o burocrata saber para quem ele deve executar o formulario, se é pro presidente, pro robô ou para o arbusto.

    public:
    //metodos publicos que podem ser acessados por qualquer classe
        AForm();
        //construtor padrão
        virtual ~AForm();
        //destrutor
    
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        //construtor parametrizado que serve para inicializar os atributos da classe
        AForm(const AForm &rhs);
        //construtor de copia que serve para inicializar os atributos da classe com os atributos de outra classe

        AForm &operator=(const AForm &rhs);
        //sobrecarga do operador de atribuição '=' para atribuir um objeto a outro

        void setTarget(std::string target);
        //metodo que atribui um alvo ao formulario
        std::string getName() const;
        //metodo que retorna o nome do formulario
        bool isSigned() const;
        //metodo que retorna se o formulario está assinado ou não
        int gradeToSign() const;
        //metodo que retorna a nota necessaria para assinar o formulario
        int gradeToExec() const;
        //metodo que retorna a nota necessaria para executar o formulario
        const std::string getTarget(void) const;
        //metodo que retorna o alvo do formulario

        void beSigned(const Bureaucrat &bureaucrat);
        //metodo que assina o formulario

        virtual void exec(Bureaucrat const &executor) const = 0;
        //metodo que executa o formulario
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
        class UnsignedFormException: public std::exception{
            //a classe UnsignedFormException é uma classe que herda da classe exception
            public:
                const char* what() const throw();
                //método que retorna uma string que descreve o erro
        };
};

std::ostream & operator<<(std::ostream & out, AForm const &rhs);
//sobrecarga do operador de inserção '<<' para inserir um objeto da classe AForm em um fluxo de saida

#endif
