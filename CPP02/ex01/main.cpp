#include "Fixed.hpp"

int main( void ) {
Fixed a;
//instancia um objeto da classe Fixed a
Fixed const b( 10 );
//instancia um objeto da classe Fixed const b com o valor 10. Por que const? Porque o valor não pode ser alterado.
Fixed const c( 42.42f );
//instancia um objeto da classe Fixed const c com o valor 42.42. Por que const? Porque o valor não pode ser alterado.
Fixed const d( b );
//instancia um objeto da classe Fixed const d com o valor do objeto b. Por que const? Porque o valor não pode ser alterado.

a = Fixed( 1234.4321f );
//atribui o valor 1234.4321 ao objeto a

std::cout << "a is " << a << std::endl;
//imprime na tela o valor do objeto a
std::cout << "b is " << b << std::endl;
//imprime na tela o valor do objeto b
std::cout << "c is " << c << std::endl;
//imprime na tela o valor do objeto c
std::cout << "d is " << d << std::endl;
//imprime na tela o valor do objeto d
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//imprime na tela o valor do objeto a convertido para inteiro
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//imprime na tela o valor do objeto b convertido para inteiro
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//imprime na tela o valor do objeto c convertido para inteiro
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//imprime na tela o valor do objeto d convertido para inteiro

return 0;
}
