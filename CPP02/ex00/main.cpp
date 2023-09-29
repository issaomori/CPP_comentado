#include "Fixed.hpp"

int main( void ){
Fixed a;
//cria um objeto a da classe Fixed
Fixed b( a );
//cria um objeto b da classe Fixed e passa o objeto a como parametro para o construtor de copia
Fixed c;
//cria um objeto c da classe Fixed
c = b;
//atribui o valor do objeto b ao objeto c

//Basicamente estou fazendo a classe a ser passada para o construtor de copia da classe b e fazendo a classe b ser atribuida a classe c.

std::cout << a.getRawBits() << std::endl;
//printa na tela o valor do numero de ponto flutuante do objeto a
std::cout << b.getRawBits() << std::endl;
//printa na tela o valor do numero de ponto flutuante do objeto b
std::cout << c.getRawBits() << std::endl;
//printa na tela o valor do numero de ponto flutuante do objeto c
return 0;
}
