#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"){
    //construtor padrão que recebe um nome e uma nota
    this->grade = 150;
}

Bureaucrat::~Bureaucrat(){
    //destrutor padrão
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name){
    //construtor parametrizado que serve para inicializar os atributos da classe
    if (grade > 150)
    //se a nota for maior que 150, lança uma exceção
        throw Bureaucrat::GradeTooLowException();
        //lança a exceção GradeTooLowException que é a exceção de nota muito baixa
    if (grade < 1)
    //se a nota for menor que 1, lança uma exceção
        throw Bureaucrat::GradeTooHighException();
        //lança a exceção GradeTooHighException que é a exceção de nota muito alta
    this->grade = grade;
    //se a nota estiver entre 1 e 150, atribui a nota ao atributo grade
    //assim perco menos tempo.
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
    //construtor de copia que serve para inicializar os atributos da classe com os atributos de outra classe
    *this = copy;
    //chama o operador de atribuição '=' para atribuir um objeto a outro
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
    //sobrecarga do operador de atribuição '=' para atribuir um objeto a outro
    if (this != &rhs)
    //se o objeto passado como parametro for diferente do objeto que chamou o metodo
        this->grade = rhs.getGrade();
        //atribui a nota do objeto passado como parametro ao objeto que chamou o metodo
    return *this;
    //retorna o objeto que chamou o metodo
}

std::string Bureaucrat::getName() const{
    //metodo que retorna o nome do burocrata
    return this->name;
}

int Bureaucrat::getGrade() const{
    //metodo que retorna a nota do burocrata
    return this->grade;
}

int Bureaucrat::incrementGrade(){
    //metodo que incrementa a nota do burocrata
    if (this->getGrade() - 1 < 1)
    //se a nota for menor que 1, lança uma exceção
        throw Bureaucrat::GradeTooHighException();
        //lança a exceção GradeTooHighException que é a exceção de nota muito alta
    this->grade--;
    //decrementa a nota do burocrata

    return this->grade;
    //retorna a nota do burocrata
}

int Bureaucrat::decrementGrade(){
    //metodo que decrementa a nota do burocrata
    if (this->getGrade()  + 1 > 150)
    //se a nota for maior que 150, lança uma exceção
        throw Bureaucrat::GradeTooLowException();
        //lança a exceção GradeTooLowException que é a exceção de nota muito baixa
    this->grade++;
    //incrementa a nota do burocrata
    return this->grade;
    //retorna a nota do burocrata
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    //metodo que retorna a mensagem de erro da exceção
    return "Grade too high.";
    //retorna a mensagem de erro da exceção
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    //metodo que retorna a mensagem de erro da exceção
    return "Grade too low.";
    //retorna a mensagem de erro da exceção
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs){
    //sobrecarga do operador de inserção '<<' para inserir um objeto em um fluxo de saida
    //a std::ostream é uma classe que representa um fluxo de saida
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    //insere o nome e a nota do burocrata no fluxo de saida
    return out;
    //retorna o fluxo de saida
}
