#include "Fixed.hpp"

Fixed::Fixed( void ){
    //construtor padrão da classe Fixed que serve para inicializar as variáveis de membro da classe.
    std::cout << "Default constructor called" << std::endl;
    // imprime na tela a mensagem "Default constructor called".
    fixed_number_point = 0;
    //inicializa a variável de membro fixed_number_point com o valor 0.
}

Fixed::~Fixed( void ){
    //destrutor da classe Fixed que serve para desalocar a memória.
    std::cout << "Destructor called" << std::endl;
    // imprime na tela a mensagem "Destructor called".
}

Fixed::Fixed(const Fixed &fixed){
    //construtor de copia que recebe um objeto da classe como parametro, o construtor de cópia é importante para que o objeto receba os valores de outro objeto da mesma classe. Então por exemplo ele pega o valor do numero de ponto flutuante de um objeto e atribui ao numero de ponto flutuante de outro objeto.
    std::cout << "Copy constructor called" << std::endl;
    //printa na tela a mensagem de que o construtor de copia foi chamado
    *this = fixed;
    //atribui o valor do numero de ponto flutuante de um objeto ao numero de ponto flutuante de outro objeto. Por que utilizo o *this? Porque o *this é um ponteiro que aponta para o objeto que está chamando o método. Então se eu tenho um objeto a e um objeto b, e eu chamo o método de copia do objeto a, o *this vai apontar para o objeto a, então eu atribuo o valor do numero de ponto flutuante do objeto b ao numero de ponto flutuante do objeto a.
}

Fixed::Fixed(const int number){
    //construtor que recebe um inteiro como parametro e converte para um numero de ponto flutuante.
    std::cout << "Int constructor called" << std::endl;
    //printa na tela a mensagem "Int constructor called".
    fixed_number_point = number << fractional_bits;
    //atribui o valor do numero de ponto flutuante ao numero de ponto flutuante do objeto. Por que utilizo o <<? Porque o << é um operador de deslocamento de bits para a esquerda, então eu desloco o numero de ponto flutuante para a esquerda o numero de vezes que tem na variavel de membro fractional_bits.
}

Fixed::Fixed(const float number){
    //construtor que recebe um float como parametro e converte para um numero de ponto flutuante.
    std::cout << "Float constructor called" << std::endl;
    //printa na tela a mensagem "Float constructor called".
    fixed_number_point = roundf(number * (1 << fractional_bits));
    //atribui o valor do numero de ponto flutuante ao numero de ponto flutuante do objeto. Por que utilizo o roundf()? Porque o roundf() arredonda o numero de ponto flutuante para o inteiro mais proximo.
}

int Fixed::getRawBits( void ) const{
    //metodo que retorna o valor do numero de ponto flutuante
    std::cout << "getRawBits member function called" << std::endl;
    //printa na tela a mensagem de que o metodo getRawBits foi chamado
    return fixed_number_point;
    //retorna o valor do numero de ponto flutuante
}

Fixed &Fixed::operator = (const Fixed &fixed){
    //operador de atribuição que recebe um objeto da classe como parametro, o operador de atribuição é importante para que o objeto receba os valores de outro objeto da mesma classe. Então por exemplo ele pega o valor do numero de ponto flutuante de um objeto e atribui ao numero de ponto flutuante de outro objeto.
    std::cout << "Copy Assignation operator called" << std::endl;
    //printa na tela a mensagem de que o operador de atribuição foi chamado
    fixed_number_point = fixed.fixed_number_point;
    //atribui o valor do numero de ponto flutuante de um objeto ao numero de ponto flutuante de outro objeto. Por que utilizo o fixed.fixed_number_point? Porque o fixed é um objeto da classe Fixed, e o fixed_number_point é uma variavel de membro da classe Fixed, então eu posso acessar a variavel de membro fixed_number_point do objeto fixed.
    return *this;
    //retorna o objeto que chamou o método
}

void Fixed::setRawBits(int const raw){
    //metodo que atribui um valor ao numero de ponto flutuante
    std::cout << "setRawBits member function called" << std::endl;
    //printa na tela a mensagem de que o metodo setRawBits foi chamado
    fixed_number_point = raw;
    //atribui o valor passado como parametro ao numero de ponto flutuante
}
 
float Fixed::toFloat( void ) const {
    //metodo que retorna o valor do numero de ponto flutuante em float
    return ((float) this->fixed_number_point / (1 << fractional_bits));
    //retorna o valor do numero de ponto flutuante em float. O fixed_number_point é um inteiro, então eu faço um cast para float. E o << é um operador de deslocamento de bits para a esquerda, então eu desloco o numero de ponto flutuante para a esquerda o numero de vezes que tem na variavel de membro fractional_bits.
}

int Fixed::toInt( void ) const {
    //metodo que retorna o valor do numero de ponto flutuante em inteiro
    return fixed_number_point >> fractional_bits;
    //retorna o valor do numero de ponto flutuante em inteiro. O fixed_number_point é um inteiro, então eu faço um cast para float. E o >> é um operador de deslocamento de bits para a direita, então eu desloco o numero de ponto flutuante para a direita o numero de vezes que tem na variavel de membro fractional_bits.
}

std::ostream &operator<<(std::ostream &out, Fixed const &fix){
//O que é o std::ostream &? O std::ostream & é um ponteiro que aponta para o objeto que está chamando o método. Ele serve para que eu possa retornar o objeto que chamou o método. A importância de retornar o objeto que chamou o método é que eu posso encadear métodos, por exemplo: std::cout << fix << std::endl;. Encadear métodos é quando eu chamo um método de um objeto e depois chamo outro método do mesmo objeto, por exemplo: objeto.metodo1().metodo2().metodo3();.
    out << fix.toFloat();
    //printa na tela o valor do numero de ponto flutuante em float.
    return out;
    //retorna o objeto que chamou o método.
}