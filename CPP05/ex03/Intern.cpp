#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy){
    *this = copy;
}

Intern &Intern::operator=(const Intern &rhs){
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(const std::string name, const std::string target){
    //metodo que cria um formulario
    const std::string typesForms[3] = {
        "presidential request",
        "robotomy request",
        "shrubbery request"
        //array de strings que contem os tipos de formularios que podem ser criados
    };
    
    AForm* (Intern::*forms[3])(const std::string) const = {
        //array de ponteiros para funções que apontam para os metodos que criam os formularios
        &Intern::createPresidentialForm,
        //o primeiro ponteiro aponta para o metodo que cria o formulario de perdao presidencial
        &Intern::createRobotomyForm,
        //o segundo ponteiro aponta para o metodo que cria o formulario de robotomia
        &Intern::createShrubberyForm
        //o terceiro ponteiro aponta para o metodo que cria o formulario de arbustos
    };
    
    for (int i = 0; i < 3; i++) {
        //loop que percorre o array de strings
        if (typesForms[i].compare(name) == 0) {
            //se o nome do formulario que o usuario quer criar for igual ao nome do formulario que está no array de strings
            std::cout << "Intern creates " << typesForms[i] << std::endl;
            //imprime que o estagiario criou o formulario
            return ((this->*forms[i])(target));
            //retorna o formulario criado e o estagiario chama o metodo que cria o formulario
        }
    }
    
    throw InvalidFormException();
    return NULL;
}

AForm *Intern::createPresidentialForm(const std::string target) const{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyForm(const std::string target) const{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyForm(const std::string target) const{
    return new PresidentialPardonForm(target);
}

const char *Intern::InvalidFormException::what(void) const throw() {
  return ("Non-existent form!!!");
}
