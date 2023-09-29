#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <exception>

class Span
// A classe Span armazena um std::vector de inteiros e tem um atributo inteiro chamado max que representa a capacidade máxima do std::vector.
{
private:
//classe privada que só pode ser acessada dentro da classe Span
    std::vector<int> vect;
    //crio um objeto da classe vector que armazena inteiros
    unsigned int max;
    //crio um atributo inteiro chamado max que representa a capacidade máxima do std::vector.

public:
//classe pública que pode ser acessada fora da classe Span
    Span();
    Span(unsigned int n);
    //construtor que recebe um inteiro como parâmetro e inicializa o atributo max com esse valor
    ~Span();
    //destrutor padrão

    Span(const Span &copy);
    //construtor de cópia
    Span &operator=(const Span &rhs);
    //sobrecarga do operador de atribuição

    unsigned int getMax(void) const;
    //método que retorna o valor do atributo max e é unsigned int porque se o valor for negativo, o programa vai dar erro, também é const porque não altera o valor do atributo max.
    const std::vector<int> &getVect(void) const;
    //método que retorna o valor do atributo vect e é const porque não altera o valor do atributo vect.

    void addNumber(int n);
    //método que adiciona um inteiro ao std::vector e é void porque não retorna nada.
    unsigned int shortestSpan(void);
    //método que retorna o menor intervalo entre dois números do std::vector e é unsigned int porque se o valor for negativo, o programa vai dar erro.
    unsigned int longestSpan(void);
    //método que retorna o maior intervalo entre dois números do std::vector e é unsigned int porque se o valor for negativo, o programa vai dar erro.

    template <typename T>
    //template que recebe um tipo T como parâmetro
    void addRange(T begin, T end);
    //método que adiciona um range de números ao std::vector e é void porque não retorna nada.

    class NotEnoughCapacity : public std::exception
    //exceção para quando o std::vector estiver cheio
    {
    public:
        const char *what(void) const throw();
    };

    class InsufficientElements : public std::exception
    //exceção para quando o std::vector tiver menos de dois elementos
    {
    public:
        const char *what(void) const throw();
    };
};

# include "Span.tpp"
//incluo o arquivo Span.tpp que contém a implementação do template
//Por que eu incluo o arquivo Span.tpp aqui em baixo e não em cima?
//Porque o compilador precisa saber o que é um template antes de compilar o arquivo Span.tpp

#endif
