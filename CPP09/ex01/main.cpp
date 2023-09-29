#include "RPN.hpp"

//Este exercício é para utilizarmos o algoritimo de RPN(notação polonesa reversa) e no que consiste esse algoritimo? Ele consiste em uma notação matemática na qual os operadores seguem seus operandos. Por exemplo, a expressão (1 - 2) * (4 + 5) seria escrita como 1 2 - 4 5 + *. A notação polonesa reversa foi inventada pelo filósofo polonês Jan Łukasiewicz na década de 1920. A notação polonesa reversa é útil em computadores porque permite que a expressão seja avaliada sem a necessidade de parênteses. Isso é feito usando uma pilha: para cada operando lido, ele é empurrado para a pilha; quando um operador é lido, os dois principais valores são retirados da pilha, o operador é aplicado a eles e o resultado é empurrado de volta para a pilha. A notação polonesa reversa também é conhecida como notação pós-fixa ou notação pós-fixa.
//Para isso o melhor container para ser utilizado é o container stack porque ele é uma pilha e a notação polonesa reversa é baseada em uma pilha. A pilha é uma estrutura de dados que segue a regra LIFO (Last In First Out), ou seja, o último elemento a entrar é o primeiro a sair. A pilha é uma estrutura de dados que permite a inserção e a remoção de elementos em uma determinada ordem. A inserção de novos elementos na pilha é conhecida como push, enquanto a remoção de elementos existentes é conhecida como pop. A pilha é um tipo de estrutura de dados abstrata que contém uma coleção de elementos (valores ou referências a valores) e suporta duas operações: push e pop. Um push adiciona um novo elemento ao topo da pilha, ou inicializa a pilha se estiver vazia, enquanto um pop remove o elemento mais recente adicionado à pilha.
int main(int argc, char **argv)
{
    RPN calculator;
	//declaro a classe RPN
	if (argc != 2)
	//se o argc for diferente de 2, ou seja, se o usuário não passar a expressão, imprimo a mensagem de erro
	{
		std::cout  << "ERROR: wrong arguments for calculation. Try '2 2 +'" << std::endl;
		return (1);
		//retorno 1 para indicar que houve um erro
	}
	try
	{
		double result;
		//declaro a variável result
		std::string calc = argv[1];
		//declaro a string calc e atribuo a ela a expressão passada pelo usuário
		result = calculator.RPNcalculate(calc);
		//atribuo à variável result o resultado da função RPNcalculate da classe RPN
        std::cout << std::string(80, '-') << std::endl;
		//coloco duas linhas para ficar mais fácil de ver o resultado
		std::cout << "Result = " << result << std::endl;
		//imprimo o resultado
        std::cout << std::string(80, '-') << std::endl;
		//coloco duas linhas para ficar mais fácil de ver o resultado
	}
	catch (const char *e)
	//se cair na exceção, imprimo a mensagem de erro
	{
		std::cerr << e << std::endl;
		//imprimo a mensagem de erro
		return (1);
		//retorno 1 para indicar que houve um erro
	}
	return (0);
	//retorno 0 para indicar que não houve erro
}

// ./RPN "2 2 +"
// 4

// ./RPN "2 2 + 5 *"
// 20

// ./RPN "2 2 + 5 * 2 / 1000 *"
// 10.000