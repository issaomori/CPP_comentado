#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150){
    //construtor padrão que recebe um nome e uma nota
    return;
}

AForm::~AForm(){
    //destrutor padrão
    return;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
    //construtor parametrizado que serve para inicializar os atributos da classe
    if (this->gradeToSign() < 1 || this->gradeToExec() < 1 || 
    this->gradeToSign() > 150 || this->gradeToExec() > 150){
        //se a assinatura ou a execução do formulario tiver uma nota menor que 1 ou maior que 150
        if (this->gradeToSign() < 1 || this->gradeToExec() < 1) {
            //se a assinatura ou a execução do formulario tiver uma nota menor que 1
            throw GradeTooHighException();
        } else
            throw GradeTooLowException();
}
}

AForm::AForm(const AForm &rhs) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150){
    //construtor de copia que serve para inicializar os atributos da classe com os atributos de outra classe
    *this = rhs;
    //chama o operador de atribuição '=' para atribuir um objeto a outro
    if (this->gradeToSign() < 1 || this->gradeToExec() < 1) {
        //se a assinatura ou a execução do formulario tiver uma nota menor que 1
    	throw GradeTooHighException();
        //lança a exceção GradeTooHighException que é a exceção de nota muito alta
	}
	if (this->gradeToSign() > 150 || this->gradeToExec() > 150) {
        //se a assinatura ou a execução do formulario tiver uma nota maior que 150
		throw GradeTooLowException();
        //lança a exceção GradeTooLowException que é a exceção de nota muito baixa
	}
    return;
}

AForm &AForm::operator=(const AForm &rhs){
    //sobrecarga do operador de atribuição '=' para atribuir um objeto a outro
    if (this == &rhs) {
        //se o objeto passado como parametro for igual ao objeto que chamou o metodo
        return *this; // Verificar se não é a mesma instância
    }

    std::cout << "Copy assignment operator called" << std::endl;

    const_cast<std::string&>(_name)= rhs.getName();
    //atribui o nome do objeto passado como parametro ao objeto que chamou o metodo
    _isSigned = rhs.isSigned();
    //atribui o valor do atributo isSigned do objeto passado como parametro ao objeto que chamou o metodo
    const_cast<int&>(_gradeToSign) = rhs.gradeToSign();
    //atribui o valor do atributo gradeToSign do objeto passado como parametro ao objeto que chamou o metodo
    const_cast<int&>(_gradeToExec) = rhs.gradeToExec();
    //atribui o valor do atributo gradeToExec do objeto passado como parametro ao objeto que chamou o metodo
    //Faço o const_cast para que eu possa alterar o valor de um atributo constante
    setTarget(rhs.getTarget());
    //atribui o alvo do objeto passado como parametro ao objeto que chamou o metodo

    return *this;
    //retorna o objeto que chamou o metodo
}

void AForm::setTarget(std::string target){
    //metodo que atribui um alvo ao formulario
    const_cast<std::string&>(this->_target) = target;
    //atribui o alvo passado como parametro ao atributo _target
    //Faço o const_cast para que eu possa alterar o valor de um atributo constante
}

std::string AForm::getName() const{
    //metodo que retorna o nome do formulario
    return this->_name;
}

bool AForm::isSigned() const{
    //metodo que retorna se o formulario está assinado ou não
    return this->_isSigned;
}

int AForm::gradeToSign() const{
    //metodo que retorna a nota necessaria para assinar o formulario
    return this->_gradeToSign;
}

int AForm::gradeToExec() const{
    //metodo que retorna a nota necessaria para executar o formulario
    return this->_gradeToExec;
}

const std::string AForm::getTarget(void) const{
    //metodo que retorna o alvo do formulario
    return this->_target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    //metodo que assina o formulario
    if (bureaucrat.getGrade() <= this->gradeToSign())
    //se a nota do burocrata for menor ou igual a nota necessaria para assinar o formulario
        this->_isSigned = true;
        //o formulario é assinado
    throw GradeTooLowException();
    //se não, lança uma exceção
}

const char *AForm::GradeTooHighException::what() const throw() {
    //metodo que retorna a mensagem de erro da exceção
	return "Grade too high.";
} 

const char *AForm::GradeTooLowException::what() const throw() {
    //metodo que retorna a mensagem de erro da exceção
	return "Grade too low.";
}

const char *AForm::UnsignedFormException::what() const throw() {
    //metodo que retorna a mensagem de erro da exceção
	return "The form is unsigned.";
}

std::ostream & operator<<(std::ostream & out, AForm const &rhs){
    //sobrecarga do operador de inserção '<<' para inserir um objeto da classe AForm em um fluxo de saida
    out << "AForm Info: " << rhs.getName() << std::endl;
    //insere o nome do formulario no fluxo de saida
    out << (rhs.isSigned() ? "yes" : "no") << std::endl;
    //insere se o formulario está assinado ou não no fluxo de saida
    out << "Grade Signed: " << rhs.gradeToSign() << std::endl;
    //insere a nota necessaria para assinar o formulario no fluxo de saida
    out << "Grade Execute: " << rhs.gradeToExec() << std::endl;
    //insere a nota necessaria para executar o formulario no fluxo de saida

    return out;
}
