#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
//biblioteca com funcionalidades de container e serve para criar um objeto da classe deque que armazena inteiros

template <typename T, typename Container = std::deque <T> >
// template <typename T, typename Container = std::deque<T>>: Isso define um template com dois parâmetros. O primeiro parâmetro é T, que é um tipo de dado genérico. O segundo parâmetro é Container, que também é um tipo genérico, mas ele tem um valor padrão std::deque<T>. Isso significa que se você usar o template sem especificar explicitamente o segundo parâmetro, ele assumirá std::deque<T> como padrão.
// typename: A palavra-chave typename é usada para indicar que T e Container são tipos genéricos. Isso permite que você use esses tipos como parâmetros de template sem conhecimento prévio de quais tipos específicos eles representarão.
// std::deque<T>: Isso é a parte padrão do segundo parâmetro Container. Está especificando que, por padrão, o tipo Container será std::deque<T>. std::deque é um tipo de contêiner em C++ que é semelhante a um vetor dinâmico, mas com algumas diferenças de desempenho e uso de memória em comparação com um vetor (std::vector).

class MutantStack : public std::stack<T, Container>
//Herdo a classe stack que armazena inteiros e recebe o valor do objeto mstack, mas de onde vem esse valor? Ele vem do template que está sendo usado na classe MutantStack. O template é uma classe que armazena inteiros e recebe o valor do objeto mstack.
{
    public:
        MutantStack() : std::stack<T, Container>(){};
        //construtor padrão
        ~MutantStack(){};
        //destrutor padrão
        MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy){};
        //construtor de cópia
        MutantStack &operator=(const MutantStack &rhs){
            //sobrecarga do operador de atribuição
            this->c = rhs.c;
            //o atributo c recebe o valor do atributo c do objeto rhs
            return *this;
            //retorna o objeto atual
        };

        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        //typedef: A palavra-chave typedef é usada para criar um alias para um tipo existente. Isso permite que você use um nome mais curto para se referir ao tipo, o que pode ser útil em alguns casos.

        iterator begin(){
            //método que retorna o valor do início do objeto mstack
            return this->c.begin();
            //retorna o valor do início do objeto mstack
        };
        iterator end(){
            //método que retorna o valor do final do objeto mstack
            return this->c.end();
            //retorna o valor do final do objeto mstack
        };
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
    //typedef: A palavra-chave typedef é usada para criar um alias para um tipo existente. Isso permite que você use um nome mais curto para se referir ao tipo, o que pode ser útil em alguns casos.

        const_iterator begin() const{
            //método que retorna o valor do início do objeto mstack
            return this->c.begin();
            //retorna o valor do início do objeto mstack
        };
        const_iterator end() const{
            //método que retorna o valor do final do objeto mstack
            return this->c.end();
            //retorna o valor do final do objeto mstack
        };
};

#endif
