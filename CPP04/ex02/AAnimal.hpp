#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
//Classe Abstrata -> não pode ser instanciada, só pode ser herdada.
// Uma classe abstrata é uma classe que não pode ser instanciada. Isso ocorre porque ela é incompleta, ou seja, ela não possui todas as implementação de métodos. Uma classe abstrata é usada apenas como uma classe base, ou seja, ela é usada apenas para ser herdada por outras classes. Tentar criar um objeto de uma classe abstrata resultará em um erro de compilação.
// Uma classe abstrata é uma classe que contém pelo menos um método virtual puro. Um método virtual puro é um método que não possui implementação na classe base, apenas nas classes derivadas. Uma classe abstrata é usada apenas como uma classe base, ou seja, ela é usada apenas para ser herdada por outras classes. Tentar criar um objeto de uma classe abstrata resultará em um erro de compilação.
// Uma classe que não possui nenhum método e os seus métodos serão inicializados em quem herdá-la.
//Classe abstrata é uma interface, ou seja, ela não possui implementação de métodos, apenas a assinatura deles.
// Classe Abstrata como um "Modelo": Você pode pensar em uma classe abstrata como um modelo ou um plano para outras classes. Ela define um conjunto de métodos e atributos que outras classes derivadas devem implementar. É como criar um esqueleto para outras classes.

// Métodos Virtuais Puros: Uma classe abstrata contém pelo menos um método virtual puro. Um método virtual puro é declarado na classe base, mas não possui uma implementação real nessa classe. Em vez disso, ele serve como um contrato que diz: "Qualquer classe que herdar de mim deve fornecer uma implementação para este método."

// Herança e Implementação: Classes derivadas herdam os métodos e atributos da classe abstrata, mas elas são obrigadas a fornecer implementações para os métodos virtuais puros definidos na classe abstrata. Isso garante que cada classe derivada tenha sua própria implementação personalizada para esses métodos.

// Instância Proibida: Como uma classe abstrata é incompleta (devido aos métodos virtuais puros sem implementação), você não pode criar objetos diretamente a partir dela. Tentar criar uma instância de uma classe abstrata resultará em erro de compilação. Afinal, como você pode criar um objeto de algo que não está completamente definido?

// Polimorfismo: Uma das principais vantagens das classes abstratas é que elas permitem o uso do polimorfismo. Isso significa que você pode tratar objetos de classes derivadas como objetos da classe base (a classe abstrata) em algumas situações, o que facilita o desenvolvimento de código flexível e extensível.

// Em resumo, classes abstratas são uma maneira de definir um conjunto de regras e comportamentos que outras classes devem seguir. Elas servem como modelos ou esqueletos para classes derivadas e garantem que essas classes tenham implementações específicas para certos métodos. O polimorfismo é habilitado por meio desse mecanismo, permitindo o uso flexível e genérico das classes derivadas.

class AAnimal{
    protected:
        std::string type;

    public:
        AAnimal(void);
        virtual ~AAnimal(void);

        AAnimal(const AAnimal &name);
        AAnimal(std::string const type);
        AAnimal &operator=(const AAnimal &name);

        std::string getType(void) const;
        void setType(std::string type);

        virtual void makeSound() const = 0;
        //Método Virtual Puro -> não possui implementação na classe base, apenas nas classes derivadas. Por que 0? Porque o 0 indica que o método é um método virtual puro. Um método virtual puro é um método que não possui implementação na classe base, apenas nas classes derivadas. Uma classe abstrata é usada apenas como uma classe base, ou seja, ela é usada apenas para ser herdada por outras classes. Tentar criar um objeto de uma classe abstrata resultará em um erro de compilação.
};

#endif
