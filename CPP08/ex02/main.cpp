#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
    //crio um objeto da classe MutantStack que armazena inteiros
	std::deque<int> deque;
    //crio um objeto da classe deque que armazena inteiros

	mstack.push(5);
    //adiciono o valor 5 ao objeto mstack
	mstack.push(17);
    //adiciono o valor 17 ao objeto mstack
	std::cout << mstack.top() << std::endl;
    //imprime o valor do topo do objeto mstack
	mstack.pop();
    //remove o valor do topo do objeto mstack
	std::cout << mstack.size() << std::endl;
    //imprime o tamanho do objeto mstack
	mstack.push(3);
    //adiciono o valor 3 ao objeto mstack
	mstack.push(5);
    //adiciono o valor 5 ao objeto mstack
	mstack.push(737);
    //adiciono o valor 737 ao objeto mstack
	mstack.push(0);
    //adiciono o valor 0 ao objeto mstack
	MutantStack<int>::iterator it = mstack.begin();
    //crio um objeto da classe iterator que armazena inteiros e recebe o valor do início do objeto mstack
	MutantStack<int>::iterator ite = mstack.end();
    //crio um objeto da classe iterator que armazena inteiros e recebe o valor do final do objeto mstack
	++it;
    //incrementa o valor do objeto it
	--it;
    //decrementa o valor do objeto it
	while (it != ite)
    //enquanto o valor do objeto it for diferente do valor do objeto ite
	{
		std::cout << *it << std::endl;
        //imprime o valor do objeto it
		++it;
        //incrementa o valor do objeto it
	}
	std::stack<int> s(mstack);
    //crio um objeto da classe stack que armazena inteiros e recebe o valor do objeto mstack

	    std::cout << "MutantStack numbers: "<< std::endl;
        //imprime a mensagem
    while (it != ite)
    //enquanto o valor do objeto it for diferente do valor do objeto ite
    {
        std::cout << *it << std::endl;
        //imprime o valor do objeto it
        ++it;
        //incrementa o valor do objeto it
    }
    std::cout << std::endl;

    std::cout << "---------------------- "<< std::endl;
    std::cout << "My own tests!!"<< std::endl;
	// Teste 1: Verificar se a pilha está vazia após a criação
	if (mstack.empty()) {
		std::cout << "Stack is empty." << std::endl;
	} else {
		std::cout << "Stack is not empty." << std::endl;
	}

	// Teste 2: Adicionar elementos à pilha e imprimir seus valores
	std::cout << "Pushing elements onto the stack:" << std::endl;
    //Empilhando elementos na pilha
	mstack.push(10);
    //adiciono o valor 10 ao objeto mstack
	mstack.push(20);
    //adiciono o valor 20 ao objeto mstack
	mstack.push(30);
    //adiciono o valor 30 ao objeto mstack

	std::cout << "Stack contents:" << std::endl;
    //imprime a mensagem
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        //enquanto o valor do objeto it for diferente do valor do objeto ite
		std::cout << *it << std::endl;
        //imprime o valor do objeto it
	}

	// Teste 3: Copiar a pilha e verificar se as cópias são iguais
	MutantStack<int> mstackCopy1 = mstack;
    //crio um objeto da classe MutantStack que armazena inteiros e recebe o valor do objeto mstack
	MutantStack<int> mstackCopy2 = mstack;
    //crio um objeto da classe MutantStack que armazena inteiros e recebe o valor do objeto mstack

	std::cout << "Comparing copied stacks:" << std::endl;
	if (mstackCopy1 == mstackCopy2) {
        //se o valor do objeto mstackCopy1 for igual ao valor do objeto mstackCopy2
		std::cout << "Copied stacks are equal." << std::endl;
	} else {
		std::cout << "Copied stacks are not equal." << std::endl;
	}

	// Teste 4: Desempilhar elementos da pilha original
	std::cout << "Popping elements from the stack:" << std::endl;
    //Desempilhando elementos da pilha
	while (!mstack.empty()) {
        //enquanto o objeto mstack não estiver vazio
		std::cout << "Popped element: " << mstack.top() << std::endl;
        //imprime o valor do topo do objeto mstack
		mstack.pop();
        //remove o valor do topo do objeto mstack
	}

	// Teste 5: Verificar se a pilha original está vazia após o desempilhamento
	if (mstack.empty()) {
		std::cout << "Stack is empty after popping." << std::endl;
	} else {
		std::cout << "Stack is not empty after popping." << std::endl;
	}

	// Teste 6: Verificar se as cópias da pilha estão vazias
	if (mstackCopy1.empty()) {
		std::cout << "Copied stack 1 is empty." << std::endl;
	} else {
		std::cout << "Copied stack 1 is not empty." << std::endl;
	}

	if (mstackCopy2.empty()) {
		std::cout << "Copied stack 2 is empty." << std::endl;
	} else {
		std::cout << "Copied stack 2 is not empty." << std::endl;
	}

}
