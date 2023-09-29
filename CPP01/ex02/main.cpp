#include <string>
#include <iostream>

//Este exercício é para entender a diferença entre ponteiros e referências.
//A diferença entre ponteiros e referências é que ponteiros são variáveis que armazenam endereços de memória e referências são apelidos para variáveis.
// Por exemplo: int a = 10; int &b = a; b é uma referência para a. Ou seja, b é um apelido para a.
//Ponteiros podem ser nulos e referências não podem ser nulas.
//Ponteiros podem ser reatribuídos e referências não podem ser reatribuídas.
//Ponteiros podem apontar para qualquer variável e referências só podem apontar para variáveis do mesmo tipo.
//Ponteiros podem apontar para vários endereços e referências só podem apontar para um endereço.
int main (){
    std::string str = "HI THIS IS BRAIN";
    //variável str do tipo string que armazena a string "HI THIS IS BRAIN"
    std::string *stringPTR = &str;
    //variável stringPTR do tipo ponteiro para string que armazena o endereço da variável str
    std::string &stringREF = str;
    //variável stringREF do tipo referência para string que armazena o endereço da variável str

    // stringREF = "gabriel";
    //ao mudar o valor da stringREF, o valor da string str também é alterado. Por que?
    //porque stringREF é uma referência para str, ou seja, stringREF é um apelido para str.
    std::cout << "str: " << &str << std::endl;
    //imprime na tela o endereço da variável str
    std::cout << "stringPTR: " << stringPTR << std::endl;
    //imprime na tela o endereço da variável stringPTR
    std::cout << "stringREF: " << &stringREF << std::endl;
    //imprime na tela o endereço da variável stringREF

    std::cout << "--------------------------------" << std::endl;

    std::cout << "str: " << str << std::endl;
    //imprime na tela o valor da variável str
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    //imprime na tela o valor da variável stringPTR
    std::cout << "stringREF: " << stringREF << std::endl;
    //imprime na tela o valor da variável stringREF

    return 0;
}
