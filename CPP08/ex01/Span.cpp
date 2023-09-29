#include "Span.hpp"

Span::Span() : max(0){
    //construtor padrão que inicializa o atributo max com 0
}

Span::Span(unsigned int n) : max(n){
    //construtor que recebe um inteiro como parâmetro e inicializa o atributo max com esse valor
}

Span::~Span(){
    //destrutor padrão
}

Span::Span(const Span &copy) : max(copy.max){
    //construtor de cópia
    this->vect = copy.vect;
    //o atributo vect recebe o valor do atributo vect do objeto copy
}

Span &Span::operator=(const Span &rhs){
    //sobrecarga do operador de atribuição
    this->vect = rhs.vect;
    //o atributo vect recebe o valor do atributo vect do objeto rhs
    this->max = rhs.max;
    //o atributo max recebe o valor do atributo max do objeto rhs
    return *this;
    //retorna o objeto atual
}

unsigned int Span::getMax(void) const{
    //método que retorna o valor do atributo max e é unsigned int porque se o valor for negativo, o programa vai dar erro, também é const porque não altera o valor do atributo max.
    return this->max;
    //retorna o valor do atributo max
}

const std::vector<int> &Span::getVect(void) const{
    //método que retorna o valor do atributo vect e é const porque não altera o valor do atributo vect.
    return this->vect;
    //retorna o valor do atributo vect
}

void Span::addNumber(int n){
    //método que adiciona um inteiro ao std::vector e é void porque não retorna nada.
    if (this->vect.size() == this->max)
    //se o tamanho do std::vector for igual ao valor do atributo max
        throw NotEnoughCapacity();
    //lança uma exceção
    this->vect.push_back(n);
    //adiciona o valor do parâmetro n ao std::vector. 
    //O que é push_back? O push_back é um método da classe vector que adiciona um elemento ao final do vector.
}

unsigned int Span::shortestSpan(void){
    //método que retorna o menor intervalo entre dois números do std::vector e é unsigned int porque se o valor for negativo, o programa vai dar erro.
    if (this->vect.size() < 2)
    //se o tamanho do std::vector for menor que 2
        throw InsufficientElements();
    //lança uma exceção
    std::vector<int> copy = this->vect;
    //crio um objeto da classe vector que armazena inteiros e recebe o valor do atributo vect
    std::sort(copy.begin(), copy.end());
    //ordena o std::vector do menor para o maior
    unsigned int shortest = UINT_MAX;
    //crio uma variável unsigned int chamada shortest que recebe o maior valor possível para um unsigned int
    for (unsigned int i = 0; i < copy.size() - 1; i++) {
        //enquanto i for menor que o tamanho do std::vector menos 1, o i serve apenas para percorrer o std::vector.
        if (copy[i + 1] - (unsigned)copy[i] < shortest)
        //se o valor do elemento seguinte menos o valor do elemento atual for menor que o valor da variável shortest
            shortest = copy[i + 1] - copy[i];
            //shortest recebe o valor do elemento seguinte menos o valor do elemento atual
    }
    return shortest;
    //retorna o valor da variável shortest
}

unsigned int Span::longestSpan(void){
    //método que retorna o maior intervalo entre dois números do std::vector e é unsigned int porque se o valor for negativo, o programa vai dar erro.
    if (this->vect.size() < 2)
    //se o tamanho do std::vector for menor que 2
        throw InsufficientElements();
    //lança uma exceção
    std::vector<int> copy = this->vect;
    //crio um objeto da classe vector que armazena inteiros e recebe o valor do atributo vect
    std::sort(copy.begin(), copy.end());
    //ordena o std::vector do menor para o maior
    return copy[copy.size() - 1] - copy[0];
    //retorna o valor do último elemento do std::vector menos o valor do primeiro elemento do std::vector
}

const char *Span::NotEnoughCapacity::what(void) const throw(){
    //exceção para quando o std::vector estiver cheio
    return "Not enough capacity";
}

const char *Span::InsufficientElements::what(void) const throw(){
    //exceção para quando o std::vector tiver menos de dois elementos
    return "Insufficient elements";
}
