#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{

    private:
    //atributos privados da classe que so podem ser acessados por membros da classe
    int _raw_bits;
    //variavel que guarda o valor do numero de ponto flutuante
    static const int fractional_bits;
    //variavel que guarda o numero de bits fracionarios e ele é constante e estatico porque nao muda e é compartilhado por todos os objetos da classe.

    public:
    //metodos publicos da classe que podem ser acessados por qualquer classe
    Fixed();
    //construtor padrão que inicializa as variaveis da classe
    ~Fixed();
    //destrutor padrão

    Fixed(const Fixed &fixed);
    //construtor de copia que recebe um objeto da classe como parametro, o construtor de cópia é importante para que o objeto receba os valores de outro objeto da mesma classe.
    Fixed &operator = (const Fixed &fixed);
    //O operador serve para atribuir o valor de um objeto a outro objeto da mesma classe.
    int getRawBits(void) const;
    //metodo que retorna o valor do numero de ponto flutuante
    void setRawBits(int const raw);
    //metodo que atribui um valor ao numero de ponto flutuante
};

#endif