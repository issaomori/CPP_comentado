#include "Fixed.hpp"

Fixed::Fixed( void ){
    //construtor da classe Fixed que serve para inicializar a variável de membro da classe
    fixed_number_point = 0;
    //inicializa a variável de membro da classe com 0
}

Fixed::~Fixed( void ){
    //destrutor da classe Fixed que serve para destruir o Fixed passado.
}

Fixed::Fixed(const Fixed &fixed){
    //construtor parametrizado da classe que serve para inicializar a variável de membro da classe com o valor passado com o objeto passado como parâmetro
    *this = fixed;
    //o ponteiro this serve para receber o parâmetro passado, já apontando para o endereço de memória do objeto que chamou o método
}

Fixed::Fixed(const int number){
    //construtor parametrizado da classe que serve para inicializar a variável de membro da classe com o valor passado com o int passado como parâmetro
    fixed_number_point = number << fractional_bits;
    //o fixed_number_point recebe o number que foi passado como parâmetro e é deslocado para a esquerda o número de bits que tem na variável de membro da classe
}

Fixed::Fixed(const float number){
    //construtor parametrizado da classe que serve para inicializar a variável de membro da classe com o valor passado com o float passado como parâmetro
    fixed_number_point = roundf(number * (1 << fractional_bits));
    //o fixed_number_point recebe o number que foi passado como parâmetro e é multiplicado pelo número de bits que tem na variável de membro da classe
}

int Fixed::getRawBits( void ) const{
    //método da classe Fixed que serve para retornar o valor da variável de membro da classe
    return fixed_number_point;
    //retorna o valor da variável de membro da classe
}

Fixed &Fixed::operator = (const Fixed &fixed){
    //sobrecarga do operador de atribuição que serve para atribuir o valor passado como parâmetro para a variável de membro da classe
    fixed_number_point = fixed.fixed_number_point;
    //o fixed_number_point recebe o fixed_number_point do objeto passado como parâmetro
    return *this;
    //retorna o ponteiro this que aponta para o endereço de memória do objeto que chamou o método
}

void Fixed::setRawBits(int const raw){
    //método da classe Fixed que serve para atribuir o valor passado como parâmetro para a variável de membro da classe
    fixed_number_point = raw;
    //o fixed_number_point recebe o valor passado como parâmetro
}
 
float Fixed::toFloat( void ) const {
    //método da classe Fixed que serve para retornar o valor da variável de membro da classe em float
    return ((float) this->fixed_number_point / (1 << fractional_bits));
    //retorna o valor da variável de membro da classe em float, basicamente fazendo um cast para float. O número de bits que tem na variável de membro da classe é deslocado para a direita
}

int Fixed::toInt( void ) const {
    //método da classe Fixed que serve para retornar o valor da variável de membro da classe em int
    return fixed_number_point >> fractional_bits;
    //retorna o valor da variável de membro da classe em int, basicamente deslocando o número de bits que tem na variável de membro da classe para a direita
}

std::ostream &operator<<(std::ostream &out, Fixed const &fix){
    //sobrecarga do operador de inserção que serve para imprimir na tela o valor da variável de membro da classe
    out << fix.toFloat();
    //imprime na tela o valor da variável de membro da classe
    return out;
    //retorna o ponteiro this que aponta para o endereço de memória do objeto que chamou o método
}

bool Fixed::operator>(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é maior que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() > left.toFloat();
    //retorna true se o valor da variável de membro da classe for maior que o valor da variável de membro da classe passada como parâmetro
}

bool Fixed::operator>=(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é maior ou igual que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() >= left.toFloat();
    //retorna true se o valor da variável de membro da classe for maior ou igual que o valor da variável de membro da classe passada como parâmetro
}

bool Fixed::operator<(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é menor que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() < left.toFloat();
    //retorna true se o valor da variável de membro da classe for menor que o valor da variável de membro da classe passada como parâmetro
}

bool Fixed::operator<=(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é menor ou igual que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() <= left.toFloat();
    //retorna true se o valor da variável de membro da classe for menor ou igual que o valor da variável de membro da classe passada como parâmetro
}

bool Fixed::operator==(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é igual que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() == left.toFloat();
    //retorna true se o valor da variável de membro da classe for igual que o valor da variável de membro da classe passada como parâmetro
}

bool Fixed::operator!=(const Fixed &left) const{
    //sobrecarga do operador de comparação que serve para comparar se o valor da variável de membro da classe é diferente que o valor da variável de membro da classe passada como parâmetro
    return this->toFloat() != left.toFloat();
    //retorna true se o valor da variável de membro da classe for diferente que o valor da variável de membro da classe passada como parâmetro
}

Fixed Fixed::operator++(void){
    //sobrecarga do operador de incremento que serve para incrementar o valor da variável de membro da classe. O operator++(void) é o pré-incremento
    ++this->fixed_number_point;
    //incrementa o valor da variável de membro da classe
    return *this;
    //retorna o ponteiro this que aponta para o endereço de memória do objeto que chamou o método
}

Fixed Fixed::operator++(int){
    //sobrecarga do operador de incremento que serve para incrementar o valor da variável de membro da classe. O operator++(int) é o pós-incremento, ou seja, incremento APENAS após a execução do método.
    Fixed aux(*this);
    //cria um objeto auxiliar do tipo Fixed que recebe o objeto que chamou o método
    this->fixed_number_point++;
    //incrementa o valor da variável de membro da classe
    return aux;
    //retorna o objeto auxiliar
}

Fixed Fixed::operator--(void){
    //sobrecarga do operador de decremento que serve para decrementar o valor da variável de membro da classe. O operator--(void) é o pré-decremento
    --this->fixed_number_point;
    //decrementa o valor da variável de membro da classe
    return *this;
    //retorna o ponteiro this que aponta para o endereço de memória do objeto que chamou o método
}

Fixed Fixed::operator--(int){
    //sobrecarga do operador de decremento que serve para decrementar o valor da variável de membro da classe. O operator--(int) é o pós-decremento, ou seja, decremento APENAS após a execução do método.
    Fixed aux(*this);
    //cria um objeto auxiliar do tipo Fixed que recebe o objeto que chamou o método
    this->fixed_number_point--;
    //decrementa o valor da variável de membro da classe
    return aux;
    //retorna o objeto auxiliar
}

Fixed Fixed::operator+(const Fixed &other) const{
    //sobrecarga do operador de soma que serve para somar o valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    Fixed tmp = (this->toFloat() + other.toFloat());
    //cria um objeto auxiliar do tipo Fixed que recebe a soma do valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    return tmp;
    //retorna o objeto auxiliar
}

Fixed Fixed::operator-(const Fixed &other) const{
    //sobrecarga do operador de subtração que serve para subtrair o valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    Fixed tmp = (this->toFloat() - other.toFloat());
    //cria um objeto auxiliar do tipo Fixed que recebe a subtração do valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    return tmp;
    //retorna o objeto auxiliar
}

Fixed Fixed::operator*(const Fixed &other) const{
    //sobrecarga do operador de multiplicação que serve para multiplicar o valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    Fixed tmp = (this->toFloat() * other.toFloat());
    //cria um objeto auxiliar do tipo Fixed que recebe a multiplicação do valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    return tmp;
    //retorna o objeto auxiliar
}

Fixed Fixed::operator/(const Fixed &other) const{
    //sobrecarga do operador de divisão que serve para dividir o valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    Fixed tmp = (this->toFloat() / other.toFloat());
    //cria um objeto auxiliar do tipo Fixed que recebe a divisão do valor da variável de membro da classe com o valor da variável de membro da classe passada como parâmetro
    return tmp;
    //retorna o objeto auxiliar
}

Fixed &min(Fixed &p1,Fixed &p2){
    //função que serve para retornar o menor valor entre dois objetos do tipo Fixed
    if (p1 < p2)
    //se o valor do objeto p1 for menor que o valor do objeto p2
        return p1;
        //retorna o objeto p1
    else
        return p2;
        //retorna o objeto p2
}

Fixed &max(Fixed &p1,Fixed &p2){
    //função que serve para retornar o maior valor entre dois objetos do tipo Fixed
    if (p1 > p2)
    //se o valor do objeto p1 for maior que o valor do objeto p2
        return p1;
        //retorna o objeto p1
    else
        return p2;
        //retorna o objeto p2
}

const Fixed &Fixed::min(const Fixed &p1,const Fixed &p2){
    //função que serve para retornar o menor valor entre dois objetos do tipo Fixed
    if (p1 < p2)
    //se o valor do objeto p1 for menor que o valor do objeto p2
        return p1;
        //retorna o objeto p1
    else
        return p2;
        //retorna o objeto p2
}

const Fixed &Fixed::max(const Fixed &p1,const Fixed &p2){
    //função que serve para retornar o maior valor entre dois objetos do tipo Fixed
    if (p1 > p2)
    //se o valor do objeto p1 for maior que o valor do objeto p2
        return p1;
        //retorna o objeto p1
    else
        return p2;
        //retorna o objeto p2
}

// Sample(const Sample& other), o que é o & ?
// O & na declaração const Sample& other indica que o parâmetro other é uma referência constante para um objeto do tipo Sample.

// Ao usar uma referência constante como parâmetro em uma função de cópia (construtor de cópia, no caso), estamos indicando que queremos receber uma referência ao objeto original que desejamos copiar, mas sem permitir sua modificação. Isso evita a necessidade de fazer uma cópia completa do objeto.
// A referência constante permite acessar os membros do objeto original, mas não permite alterar seu estado. Isso é útil para operações de cópia, onde apenas desejamos obter os valores dos membros do objeto original para criar uma cópia correspondente.

// Sample& operator=(const Sample& other), o que é o &?
// O & na declaração Sample& operator=(const Sample& other) indica que o retorno do operador de atribuição é uma referência a um objeto do tipo Sample.

// Quando um operador de atribuição é definido como uma função membro de uma classe, geralmente é desejável retornar uma referência ao próprio objeto atualizado após a atribuição. Isso permite encadear múltiplas atribuições em uma única expressão, conhecida como "chaining".

// Ao retornar uma referência Sample&, o operador de atribuição permite que a atribuição seja usada em uma expressão posterior, por exemplo:
// Sample a;
// Sample b;
// Sample c;

// a = b = c;  // Chaining de atribuição

// Nesse exemplo, b = c retorna uma referência a b, e em seguida, a = b retorna uma referência a a. Essa referência é usada para encadear as atribuições subsequentes.

// Além disso, retornar uma referência também permite que o operador de atribuição seja usado em um contexto onde o objeto atualizado é necessário ou esperado, como em uma função que espera receber um objeto Sample& como argumento por referência.

// Vou dar um exemplo de ponto fixo usando dinheiro como representação. Suponhamos que você esteja desenvolvendo um programa financeiro e precise lidar com valores monetários com precisão fixa. Você pode usar números de ponto fixo para representar valores em centavos, onde uma parte fixa dos dígitos representa os reais e os dígitos restantes representam os centavos.

// Por exemplo, se você quisesse representar R$ 123,45 em um sistema de ponto fixo, poderia representá-lo como 12345 (123 reais e 45 centavos). Agora, vamos realizar algumas operações simples:

// Adição: Se você quisesse adicionar R$ 50,75 a R$ 123,45, você poderia somar 5075 (50 reais e 75 centavos) a 12345 (123 reais e 45 centavos) para obter 17420 (174 reais e 20 centavos).

// Subtração: Se você quisesse subtrair R$ 10,25 de R$ 123,45, você poderia subtrair 1025 (10 reais e 25 centavos) de 12345 (123 reais e 45 centavos) para obter 11320 (113 reais e 20 centavos).

// Multiplicação: Se você quisesse multiplicar R$ 12,50 por 2, você poderia multiplicar 1250 (12 reais e 50 centavos) por 2 para obter 2500 (25 reais).

// Divisão: Se você quisesse dividir R$ 75,00 por 3, você poderia dividir 7500 (75 reais) por 3 para obter 2500 (25 reais).

// Essa representação de ponto fixo permite que você realize operações financeiras com precisão fixa, mantendo a parte decimal sempre com dois dígitos para centavos. Isso é útil em aplicações financeiras e contábeis onde a precisão é fundamental e você deseja evitar erros de arredondamento que podem ocorrer com números de ponto flutuante.
