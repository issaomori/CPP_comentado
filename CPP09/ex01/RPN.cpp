#include "RPN.hpp"

RPN::RPN(){}
//construtor padrão

RPN::~RPN(){}
//destrutor padrão

RPN::RPN(const RPN &copy)
//construtor de cópia parametrizado
{
    *this = copy;
    //chamo o operador de atribuição sobrecarregado
}

RPN &RPN::operator=(const RPN &rhs)
//operador de atribuição sobrecarregado para atribuir um objeto a outro
{
    if (this != &rhs)
    //se o objeto passado como parâmetro for diferente do objeto que chamou a função
    {
        *this = rhs;
        //atribuo o objeto passado como parâmetro ao objeto que chamou a função
    }
    return (*this);
    //retorno o objeto que chamou a função
}

double RPN::RPNcalculate(std::string arg) {
//método para calcular a expressão RPN e retornar o resultado como double
    if (!IsValidExpression(arg))
    //se a expressão não for válida, lanço uma exceção
        throw "Error: Invalid expression";
        //lanço a exceção

    std::stack<double> rpn;
    //declaro um container stack de double
    std::istringstream iss(arg);
    //declaro um istringstream e passo a string como parâmetro, ela vai separar a string em tokens e o que são tokens? Os números e os operadores
    std::string token;
    //declaro uma string token

    while (iss >> token) {
        //enquanto o istringstream for passando os tokens para a string token
        if (token.size() == 1 && IsOperator(token[0])) {
            // se apenas tiver um caractere e esse caractere for um operador
            if (rpn.size() < 2)
            //se o tamanho da stack for menor do que 2, ou seja, se não tiver pelo menos 2 números na stack, lanço uma exceção
                throw "Error";
                //lanço a exceção
            PerformOperation(rpn, token[0]);
            //chamo a função PerformOperation passando a stack e o operador como parâmetros
        } else {
            double number = strtod(token.c_str(), NULL);
            //converto a string token para double e atribuo à variável number
            rpn.push(number);
            //adiciono o número à stack
        }
    }

    if (rpn.size() != 1)
    //se o tamanho da stack for diferente de 1, ou seja, se não tiver apenas um número na stack, lanço uma exceção
        throw "Error: RPN error execution";
        //lanço a exceção
    else
        return rpn.top();
        //se não, retorno o topo da stack
}

bool RPN::IsOperator(char c) {
    //método para verificar se o caractere passado como parâmetro é um operador
    return (c == '+' || c == '-' || c == '*' || c == '/');
    //se o caractere for um dos operadores, retorno true, se não, retorno false
}

bool RPN::IsValidExpression(std::string arg) {
    //método para verificar se a expressão é válida
    std::stack<char> operators;
    //declaro uma stack de char
    std::istringstream iss(arg);
    //declaro um istringstream e passo a string como parâmetro, ela vai separar a string em tokens e o que são tokens? Os números e os operadores
    std::string token;
    //declaro uma string token

    while (iss >> token) {
        //enquanto o istringstream for passando os tokens para a string token
        if (token.size() == 1 && IsOperator(token[0])) {
            // se apenas tiver um caractere e esse caractere for um operador
            if (operators.size() < 2)
                return false; // Não há operandos suficientes para o operador
            operators.push(token[0]);
            //adiciono o operador à stack
        } else {
            double number;
            //declaro uma variável double
            if (std::istringstream(token) >> number) {
                // É um número, não faz nada
            } else {
                // Não é um operador nem um número válido
                return false;
            }
        }
    }

    // Deve haver um operador a menos do que o número de operandos
    return (operators.size() == 1);
}
// A função RPNcalculate e a função IsValidExpression têm uma checagem semelhante, mas elas servem a propósitos diferentes dentro do seu código.

// RPNcalculate:

// Esta função é responsável por calcular uma expressão na notação polonesa reversa (RPN) e retornar o resultado como um número double.
// Ela usa a função IsValidExpression para verificar se a expressão RPN fornecida como argumento é válida.
// Se a expressão não for válida, ela lança uma exceção, pois não pode continuar o cálculo com uma expressão inválida.
// Em seguida, ela realiza a avaliação da expressão RPN e retorna o resultado ou lança exceções adicionais se ocorrerem erros durante a avaliação.
// IsValidExpression:

// Esta função é responsável por verificar se a expressão RPN fornecida como argumento é válida antes de qualquer cálculo ocorrer.
// Ela faz uma verificação preliminar para garantir que a expressão RPN esteja bem formada e que existam operandos suficientes para cada operador.
// Se a expressão RPN não for válida, ela retorna false.
// Se a expressão RPN for válida, ela retorna true.
// Portanto, ambas as verificações são necessárias em níveis diferentes de validação:

// IsValidExpression é uma verificação de pré-condição que acontece antes de qualquer cálculo ser realizado. Ela impede que cálculos sejam feitos em expressões RPN inválidas.
// RPNcalculate é a função principal de cálculo e confia em IsValidExpression para garantir que a expressão RPN seja válida antes de iniciar os cálculos.
// Essa abordagem ajuda a garantir que o código não tente calcular uma expressão RPN inválida e, ao mesmo tempo, permite que você tenha um controle mais granular sobre os erros, lançando exceções específicas para diferentes cenários de erro em RPNcalculate. Portanto, a duplicação da verificação é justificada pelos diferentes papéis que essas funções desempenham em seu programa.

void RPN::PerformOperation(std::stack<double>& rpn, char op) {
    //método para realizar a operação
    double number2 = rpn.top();
    //declaro uma variável double e atribuo a ela o topo da stack
    rpn.pop();
    //removo o topo da stack
    double number1 = rpn.top();
    //declaro uma variável double e atribuo a ela o topo da stack
    rpn.pop();
    //removo o topo da stack
    double result;
    //declaro uma variável double

    //Por que eu adiciono e removo os números da stack? Porque eu preciso dos dois números para realizar a operação, então eu removo os dois números da stack, realizo a operação e adiciono o resultado à stack

    switch (op) {
        //faço um switch case para verificar qual operador foi passado como parâmetro. O switch case é uma estrutura de controle que permite que o valor de uma variável ou expressão seja testado em relação a um valor de lista constante. Cada valor é chamado de case e a variável é verificada para cada case.
        case '+':
            result = number1 + number2;
            //se o operador for +, atribuo à variável result a soma dos dois números
            break;
        case '-':
            result = number1 - number2;
            //se o operador for -, atribuo à variável result a subtração dos dois números
            break;
        case '*':
            result = number1 * number2;
            //se o operador for *, atribuo à variável result a multiplicação dos dois números
            break;
        case '/':
        //se o operador for /, atribuo à variável result a divisão dos dois números
            if (number2 == 0)
            //se o número 2 for igual a 0, lanço uma exceção
                throw "Error: Division by zero";
                //lanço a exceção
            result = number1 / number2;
            //atribuo à variável result a divisão dos dois números
            break;
        default:
            //se o operador não for nenhum dos operadores acima, lanço uma exceção
            throw "Error: Invalid operator";
    }

    rpn.push(result);
    //adiciono o resultado à stack
}
