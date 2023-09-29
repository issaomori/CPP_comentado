#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//Neste projeto os pontos que serão avaliados são:
//Polimorfismo e classes abstratas
//O que é polimorfismo?
// O polimorfismo em C++ é um conceito de programação orientada a objetos que se refere à capacidade de objetos de classes diferentes responderem de maneira similar a chamadas de função idênticas. Isso significa que você pode usar uma interface comum para interagir com objetos de classes diferentes, sem se preocupar com os detalhes específicos de cada classe.
// Existem dois principais tipos de polimorfismo em C++:

// Polimorfismo de Sobrecarga de Função (Compile-time Polymorphism): Isso ocorre quando você tem várias funções com o mesmo nome em uma classe, mas com diferentes tipos ou números de parâmetros. O compilador decide qual função chamar com base nos argumentos fornecidos durante a compilação.

// Polimorfismo de Substituição (Run-time Polymorphism): Este é o tipo mais comum de polimorfismo e ocorre quando você usa herança e classes derivadas. É baseado no uso de funções virtuais e aponta para objetos de classe base. Os objetos de classes derivadas podem substituir as funções virtuais da classe base para fornecer implementações específicas. A escolha da função a ser executada ocorre em tempo de execução, com base no tipo real do objeto. Este é o tipo de polimorfismo que será abordado neste projeto.

// O polimorfismo é uma ferramenta poderosa na programação orientada a objetos, pois permite escrever código mais flexível e genérico. Isso facilita a criação de hierarquias de classes e o uso de interfaces comuns para objetos que compartilham características semelhantes, mas também têm comportamentos específicos. Isso torna o código mais fácil de entender, manter e estender.

int main()
{
    const Animal* animal = new Animal();
    //aloco um ponteiro constante do tipo Animal, que aponta para um novo objeto do tipo Animal
    const Animal* cat = new Cat();
    //aloco um ponteiro constante do tipo Animal, que aponta para um novo objeto do tipo Cat
    const Animal* dog = new Dog();
    //aloco um ponteiro constante do tipo Animal, que aponta para um novo objeto do tipo Dog
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    //aloco um ponteiro constante do tipo WrongAnimal, que aponta para um novo objeto do tipo WrongAnimal
    const WrongCat* wrongCat = new WrongCat();
    //aloco um ponteiro constante do tipo WrongAnimal, que aponta para um novo objeto do tipo WrongCat

    std::cout << "Testing Animal:" << std::endl;
    //imprimo na tela a string "Testing Animal:"
    std::cout << "Type: " << animal->getType() << std::endl;
    //imprimo na tela qual o tipo do animal
    animal->makeSound();
    //imprimo na tela o som que o animal faz

    std::cout << "\nTesting Cat:" << std::endl;
    //imprimo na tela a string "Testing Cat:"
    std::cout << "Type: " << cat->getType() << std::endl;
    //imprimo na tela qual o tipo do animal
    cat->makeSound();
    //imprimo na tela o som que o animal faz

    std::cout << "\nTesting Dog:" << std::endl;
    //imprimo na tela a string "Testing Dog:"
    std::cout << "Type: " << dog->getType() << std::endl;
    //imprimo na tela qual o tipo do animal
    dog->makeSound();
    //imprimo na tela o som que o animal faz

    std::cout << "\nTesting WrongAnimal:" << std::endl;
    //imprimo na tela a string "Testing WrongAnimal:"
    std::cout << "Type: " << wrongAnimal->getType() << std::endl;
    //imprimo na tela qual o tipo do animal
    wrongAnimal->makeSound();
    //imprimo na tela o som que o animal faz

    std::cout << "\nTesting WrongCat:" << std::endl;
    //imprimo na tela a string "Testing WrongCat:"
    std::cout << "Type: " << wrongCat->getType() << std::endl;
    //imprimo na tela qual o tipo do animal
    wrongCat->makeSound();
    //imprimo na tela o som que o animal faz

    delete animal;
    //deleto o ponteiro animal
    delete cat;
    //deleto o ponteiro cat
    delete dog;
    //deleto o ponteiro dog
    delete wrongAnimal;
    //deleto o ponteiro wrongAnimal
    delete wrongCat;
    //deleto o ponteiro wrongCat

    return 0;
}
