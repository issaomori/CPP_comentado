#include "Form.hpp"

//Neste exercicio é adicionado uma nova classe chamada Form que é uma classe que representa um formulario, ou seja, um documento que precisa ser assinado por um burocrata para ser executado.
//O burocrata ganha um novo metodo chamado signForm que serve para assinar um formulario, caso o burocrata não tenha a nota necessaria para assinar o formulario, é lançada uma exceção.

int main() {
    try {
        // Criando burocratas
        Bureaucrat bureaucrat1("Alice", 100);
        Bureaucrat bureaucrat2("Bob", 50);

        // Criando formulários
        Form form1("Tax Form", 75, 100);
        Form form2("Approval Form", 40, 60);

        // Imprimindo informações iniciais dos formulários e dos burocratas
        std::cout << "Initial state of forms and bureaucrats:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;

        // Tentando assinar as formas pelos burocratas
        std::cout << "Trying to sign the forms:" << std::endl;
        bureaucrat1.signForm(form1);
        //burocrata1 tenta assinar o formulario1, vai dar erro porque a nota dele é 100 e a nota necessaria para assinar o formulario1 é 75 para menos
        bureaucrat2.signForm(form2);
        //burocrata2 tenta assinar o formulario2, vai dar erro porque a nota dele é 50 e a nota necessaria para assinar o formulario2 é 40 para menos
        std::cout << std::endl;

        //Testando o novo método do burocrata
        std::cout << "Testing beSign:" << std::endl;
		try
		{
			form1.beSigned(bureaucrat2);
            //tento assinar o formulario1 com o burocrata2, vai dar certo porque a nota dele é 50 e a nota necessaria para assinar o formulario1 é 75 para menos
			std::cout << form1 << std::endl;
		}
		catch(const std::exception& e)
        //caso não consiga assinar o formulario1 com o burocrata2, lança uma exceção
		{
			std::cerr << e.what() << std::endl;
		}
        std::cout << std::endl;

        // Imprimindo o estado das formas após a tentativa de assinatura
        std::cout << "State of forms after signing attempt:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (std::exception& e) {
        //caso não consiga criar um burocrata ou um formulario, lança uma exceção
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
