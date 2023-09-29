#include "Whatever.hpp"

int main(void){
	int a = 2;
	int b = 3;
	//inicializa as variáveis

	std::cout << "a=" << a << ", b = " << b <<std::endl;
	//imprime as variáveis
	::swap(a, b);
	//troca as variáveis
	std::cout << "SWAP: a=" << a << ", b = " << b <<std::endl;
	//imprime as variáveis trocadas
	std::cout << "min(a,b)=" << ::min(a,b) <<std::endl;
	//imprime o menor valor
	std::cout << "max(a,b)=" << ::max(a,b)<<std::endl;
	//imprime o maior valor
	std::string c="chaine1";
	std::string d="chaine2";
	//inicializa duas strings
	std::cout << "c=" << c << ", d = " <<d<<std::endl;
	//imprime as strings
	::swap(c, d);
	//troca as strings
	std::cout << "SWAP: c=" << c << ", d = " <<d<<std::endl;
	//imprime as strings trocadas
	std::cout << "min(c,d) = " << ::min(c,d) <<std::endl;
	//imprime a menor string
	std::cout << "max(c,d) = " << ::max(c,d) <<std::endl;
	//imprime a maior string

	return 0;
}


class Awesome
//classe Awesome para testar
{
  public:
  //metodos publicos da classe que podem ser acessados por outras classes
    Awesome(void) : _n(0) {}
	//construtor inicializa _n com 0
    Awesome( int n ) : _n( n ) {}
	//construtor inicializa _n com n
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	//sobrecarga do operador de atribuição
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	//sobrecarga do operador de comparação ==
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	//sobrecarga do operador de comparação !=
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	//sobrecarga do operador de comparação >
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	//sobrecarga do operador de comparação <
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	//sobrecarga do operador de comparação >=
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	//sobrecarga do operador de comparação <=
    int get_n() const { return _n; }
	//metodo que retorna o valor de _n
  private:
  //atributos privados da classe que só podem ser acessados por metodos da classe
    int _n;
	//atributo _n do tipo int
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
//sobrecarga do operador de inserção << para imprimir o valor de _n no terminal

int main(void)
{
	Awesome a(2), b(4);
	//inicializa duas classes Awesome a e b

        swap(a, b);
		//troca as classes
        std::cout << a << " " << b << std::endl;
		//imprime as classes trocadas
        std::cout << max(a, b) << std::endl;
		//imprime a maior classe
        std::cout << min(a, b) << std::endl;
		//imprime a menor classe
        return (0);
}
