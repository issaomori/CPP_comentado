#include "Iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    //inicializa um array de inteiros
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    //inicializa um array de doubles
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    //inicializa um array de chars

    std::cout << "Original intArray: ";
    iter(intArray, 5, printElemLn);
    //aplica a função iter ao array intArray, com tamanho 5 e a função printElemLn

    std::cout << "Original doubleArray: ";
    iter(doubleArray, 5, printElemLn);
    //aplica a função iter ao array doubleArray, com tamanho 5 e a função printElemLn

    std::cout << "Original charArray: ";
    iter(charArray, 5, printElemLn);
    //aplica a função iter ao array charArray, com tamanho 5 e a função printElemLn

    std::cout << "Incremented intArray: ";
    iter(intArray, 5, addOne);
    //aplica a função iter ao array intArray, com tamanho 5 e a função addOne
    iter(intArray, 5, printElemLn);
    //aplica a função iter ao array intArray, com tamanho 5 e a função printElemLn

    std::cout << "Decremented doubleArray: ";
    iter(doubleArray, 5, reduceOne);
    //aplica a função iter ao array doubleArray, com tamanho 5 e a função reduceOne
    iter(doubleArray, 5, printElemLn);
    //aplica a função iter ao array doubleArray, com tamanho 5 e a função printElemLn

    return 0;
}

class Awesome
//crio uma classe Awesome para testar
{
  public:
    //metodos publicos da classe que podem ser acessados por outras classes
    Awesome( void ) : _n( 42 ) { return; }
    //construtor inicializa _n com 42
    int get( void ) const { return this->_n; }
    //metodo que retorna o valor de _n
  private:
    int _n;
    //variavel privada _n
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
//sobrecarga do operador de inserção << para imprimir o valor de _n no terminal
{
  o << rhs.get();
  //imprime o valor de _n
  return o;
  //retorna o valor de o
}

template< typename T >
void print( T& x )
//função print que recebe um elemento do tipo T e imprime esse elemento
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  //inicializa um array de inteiros
  Awesome tab2[5];
  //inicializa um array de classes Awesome

  iter( tab, 5, print<const int> );
    //aplica a função iter ao array tab, com tamanho 5 e a função print<const int>
  iter( tab2, 5, print<Awesome> );
    //aplica a função iter ao array tab2, com tamanho 5 e a função print<Awesome>

    //o resultado esperado é "0 1 2 3 4 42 42 42 42 42" porque a função print<const int> imprime o array tab e a função print<Awesome> imprime o array tab2. Por que o valor da tab2 sai tudo 42? Porque o construtor da classe Awesome inicializa _n com 42.

  return 0;
}
