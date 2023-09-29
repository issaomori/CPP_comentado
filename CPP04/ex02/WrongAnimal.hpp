#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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
class WrongAnimal{
    //classe WrongAnimal
    protected:
        //atributo protegido -> só pode ser acessado pela própria classe e pelas classes que herdam dela.
        std::string type;
        //atributo tipo string
    
    public:
    //construtor parametrizado -> serve para inicializar um objeto com os valores passados.
        WrongAnimal(void);
        //construtor padrão inicializando o atributo type
        ~WrongAnimal(void);
        //destrutor padrão

        WrongAnimal(std::string type);
        //construtor parametrizado que recebe um parâmetro tipo que é o animal e inicializa o objeto com o valor passado.
        WrongAnimal(const WrongAnimal &name);
        //construtor de cópia que recebe um objeto como parâmetro e copia os valores dele para o objeto que está sendo inicializado.
        WrongAnimal &operator=(const WrongAnimal &name);
        //operador de atribuição sobrecarregado que recebe um objeto como parâmetro e atribui os valores dele ao objeto que está chamando o método.

        std::string getType(void) const;
        //método que retorna o tipo do animal
        void setType(std::string type);
        //método que recebe um parâmetro tipo e atribui esse valor ao atributo type do objeto que está chamando o método.
        
        void makeSound(void) const;
        //método que faz o som do animal

};
#endif