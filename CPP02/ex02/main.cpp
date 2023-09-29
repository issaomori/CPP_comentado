#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	//instancia um objeto Fixed a sem valor
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//instancia um objeto Fixed b com valor 5.05f * 2

	std::cout << a << std::endl;
	//imprime na tela o valor do objeto a que é 0.
	std::cout << ++a << std::endl;
	//imprime na tela o valor do objeto a que é 1, pois eu pré-incrementei o valor do objeto a, ou 
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;		

std::cout << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	return 0;
}

// Pré-incremento (++a): O operador pré-incremento incrementa o valor de 'a' e, em seguida, retorna o valor atualizado. No seu caso, o valor de 'a' é incrementado de 0 para 0.00390625 antes de ser impresso.

// Pós-incremento (a++): O operador pós-incremento retorna o valor atual de 'a' e, em seguida, incrementa 'a'. Portanto, quando você imprime a++, você vê o valor antes do incremento (0.00390625) e, em seguida, 'a' é incrementado para 0.0078125.

// Para as demais operações aritméticas (soma, subtração, multiplicação, divisão), os valores são tratados como números de ponto flutuante porque a classe Fixed usa uma representação de ponto fixo, e a conversão para ponto flutuante ocorre durante as operações.

// Mas por que o Fixed é float?
// A classe Fixed que você implementou é realmente destinada a trabalhar com valores fixos, não com números em ponto flutuante. Eu cometi um erro ao analisar o código.

// Aqui está o esclarecimento correto:

// A classe Fixed é destinada a armazenar valores fixos com uma parte fracionária, mas ela não é um tipo de ponto flutuante real. O valor interno é armazenado como um inteiro fixo com ponto flutuante implícito. Isso significa que o valor interno é representado como um número inteiro onde uma parte dos bits representa a parte inteira e a outra parte representa a parte fracionária.

// A função toFloat() que você implementou é usada para converter o valor interno para ponto flutuante para que você possa imprimi-lo como um número de ponto flutuante. Ela faz essa conversão para facilitar a saída dos valores, mas o valor real armazenado na classe Fixed é uma representação fixa com ponto flutuante implícito.

// Portanto, quando você vê valores em ponto flutuante (como 0.00390625), isso é apenas uma representação do valor interno da classe Fixed, que inclui uma parte fracionária fixa. Os valores não são realmente armazenados ou manipulados como valores de ponto flutuante, mas sim como valores fixos com ponto flutuante implícito.

// Claro, vou dar um exemplo de ponto fixo usando dinheiro como representação. Suponhamos que você esteja desenvolvendo um programa financeiro e precise lidar com valores monetários com precisão fixa. Você pode usar números de ponto fixo para representar valores em centavos, onde uma parte fixa dos dígitos representa os reais e os dígitos restantes representam os centavos.

// Por exemplo, se você quisesse representar R$ 123,45 em um sistema de ponto fixo, poderia representá-lo como 12345 (123 reais e 45 centavos). Agora, vamos realizar algumas operações simples:

// Adição: Se você quisesse adicionar R$ 50,75 a R$ 123,45, você poderia somar 5075 (50 reais e 75 centavos) a 12345 (123 reais e 45 centavos) para obter 17420 (174 reais e 20 centavos).

// Subtração: Se você quisesse subtrair R$ 10,25 de R$ 123,45, você poderia subtrair 1025 (10 reais e 25 centavos) de 12345 (123 reais e 45 centavos) para obter 11320 (113 reais e 20 centavos).

// Multiplicação: Se você quisesse multiplicar R$ 12,50 por 2, você poderia multiplicar 1250 (12 reais e 50 centavos) por 2 para obter 2500 (25 reais).

// Divisão: Se você quisesse dividir R$ 75,00 por 3, você poderia dividir 7500 (75 reais) por 3 para obter 2500 (25 reais).

// Essa representação de ponto fixo permite que você realize operações financeiras com precisão fixa, mantendo a parte decimal sempre com dois dígitos para centavos. Isso é útil em aplicações financeiras e contábeis onde a precisão é fundamental e você deseja evitar erros de arredondamento que podem ocorrer com números de ponto flutuante.