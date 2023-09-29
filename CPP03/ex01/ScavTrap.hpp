#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    //ScavTrap é a classe filha da classe ClapTrap, ou seja, a classe ScavTrap herda todos os atributos e métodos da classe ClapTrap.

    
    //classe ScavTrap que herda da classe ClapTrap. Como assim herda? A classe ScavTrap tem todos os atributos e métodos da classe ClapTrap, porém ela pode ter mais atributos e métodos. Neste caso até os atributos privados da classe ClapTrap podem ser acessados pela classe ScavTrap? não, mesmo utilizando herança ainda quem só pode acessar os atributos privados é a classe, outras classes não podem acessar os atributos privados da classe ClapTrap.
    //Qual a importância da herança? A herança serve para reaproveitar código, ou seja, se eu tenho uma classe que tem vários atributos e métodos e eu quero criar uma classe que tenha os mesmos atributos e métodos da classe anterior, eu posso herdar da classe anterior e não preciso reescrever os atributos e métodos da classe anterior.
    public:
    ScavTrap();
    ~ScavTrap();

    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &name);
    ScavTrap &operator=(ScavTrap const &name);

    void attack(const std::string &target);
    void guardGate(void);
};

// 1. **Herança na programação orientada a objetos**: A herança é um conceito fundamental na programação orientada a objetos (POO). Ela permite que uma classe (a classe derivada) herde os atributos e métodos de outra classe (a classe base ou superclasse), tornando-os disponíveis para reutilização e extensão na classe derivada.

// 2. **Classe base e classe derivada**: Na herança, a classe base (também chamada de superclasse ou classe pai) é a classe original da qual você herda atributos e métodos, enquanto a classe derivada (também chamada de subclasse ou classe filha) é a classe que herda esses membros da classe base.

// 3. **Acesso aos membros privados**: Em C++, quando uma classe derivada herda de uma classe base, ela não pode acessar os membros privados da classe base diretamente. Ela só pode acessar os membros públicos e protegidos da classe base. Portanto, sua afirmação de que "somente a classe ScavTrap pode acessar os atributos privados da classe ClapTrap" não está completamente correta. A classe ScavTrap só pode acessar os membros públicos e protegidos da classe ClapTrap.

// 4. **Extensão da funcionalidade**: Uma das vantagens da herança é que a classe derivada pode adicionar novos atributos e métodos, bem como modificar ou sobrescrever os métodos herdados da classe base. Isso permite que você estenda a funcionalidade da classe base de acordo com as necessidades da classe derivada.

// 5. **Chamada de construtores e destrutores**: Note que você também está criando construtores e destrutores para a classe derivada ScavTrap. Esses construtores e destrutores podem chamar explicitamente os construtores e destrutores correspondentes da classe base ClapTrap usando a inicialização de membro. Isso garante que os atributos da classe base sejam inicializados corretamente ao criar ou destruir objetos da classe derivada.

// Em resumo, sua definição de herança e a estrutura da classe ScavTrap parecem estar indo na direção certa. Certifique-se de que a classe ScavTrap use efetivamente os membros herdados da classe ClapTrap e implemente ou sobrescreva os métodos conforme necessário para a funcionalidade específica da classe ScavTrap.


#endif