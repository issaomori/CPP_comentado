//Fixed point é um exercício para entender como funciona a forma canônica de uma classe, que é composta por um construtor padrão, um destrutor padrão, um construtor de cópia e um operador de atribuição.
//Tudo o que é feito no exercício 00 e 01 é para preparar para o 02. Então no primeiro exercício é feito tudo sobre a forma canônica.
#include "Fixed.hpp"

Fixed::Fixed( void ){
    //construtor padrão que inicializa as variaveis da classe
    std::cout << "Default constructor called" << std::endl;
    //printa na tela a mensagem de que o construtor padrão foi chamado
    _raw_bits = 0;
    //inicializa a variavel que guarda o valor do numero de ponto flutuante com 0
}

Fixed::~Fixed( void ){
    //destrutor padrão
    std::cout << "Destructor called" << std::endl;
    //printa na tela a mensagem de que o destrutor padrão foi chamado
}

Fixed::Fixed(const Fixed &fixed){
    //construtor de copia que recebe um objeto da classe como parametro, o construtor de cópia é importante para que o objeto receba os valores de outro objeto da mesma classe. Então por exemplo ele pega o valor do numero de ponto flutuante de um objeto e atribui ao numero de ponto flutuante de outro objeto.
    std::cout << "Copy constructor called" << std::endl;
    //printa na tela a mensagem de que o construtor de copia foi chamado
    *this = fixed;
    //atribui o valor do numero de ponto flutuante de um objeto ao numero de ponto flutuante de outro objeto. Por que utilizo o *this? Porque o *this é um ponteiro que aponta para o objeto que está chamando o método. Então se eu tenho um objeto a e um objeto b, e eu chamo o método de copia do objeto a, o *this vai apontar para o objeto a, então eu atribuo o valor do numero de ponto flutuante do objeto b ao numero de ponto flutuante do objeto a.
}

int Fixed::getRawBits( void ) const{
    //metodo que retorna o valor do numero de ponto flutuante
    std::cout << "getRawBits member function called" << std::endl;
    //printa na tela a mensagem de que o metodo getRawBits foi chamado
    return _raw_bits;
    //retorna o valor do numero de ponto flutuante
}

Fixed &Fixed::operator = (const Fixed &fixed){
    //explicação em baixo
    std::cout << "Copy assignment operator called" << std::endl;
    //printa na tela a mensagem de que o operador de atribuição foi chamado
    _raw_bits = fixed.getRawBits();
    //atribui o valor do numero de ponto flutuante de um objeto ao numero de ponto flutuante de outro objeto. Por que utilizo o fixed.getRawBits()? Porque o fixed é um objeto da classe Fixed, e o método getRawBits() é um método da classe Fixed, então eu posso chamar o método getRawBits() do objeto fixed.
    return *this;
    //retorna o objeto que chamou o método
}

void Fixed::setRawBits(int const raw){
    //metodo que atribui um valor ao numero de ponto flutuante
    std::cout << "setRawBits member function called" << std::endl;
    //printa na tela a mensagem de que o metodo setRawBits foi chamado
    _raw_bits = raw;
    //atribui o valor passado como parametro ao numero de ponto flutuante
}

