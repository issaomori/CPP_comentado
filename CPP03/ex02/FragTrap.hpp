#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    //classe FragTrap que herda da classe ClapTrap
    public:
    //métodos públicos que podem ser acessados por qualquer classe.
        FragTrap();
        //construtor padrão que inicializa os atributos da classe.
        ~FragTrap();
        //destrutor padrão.

        FragTrap(std::string name);
        //construtor paramétrico que inicializa os atributos da classe. O construtor paramétrico é utilizado para inicializar um objeto com um valor específico.
        FragTrap(FragTrap const &name);
        //construtor de cópia que inicializa os atributos da classe. O construtor de cópia é utilizado para inicializar um objeto com os valores de outro objeto já existente.
        FragTrap &operator=(FragTrap const &name);
        //sobrecarga do operador de atribuição "=". A sobrecarga de operadores serve para definir o comportamento de um operador para um tipo de dado definido pelo usuário.
    
        void highFivesGuys(void);
        //método que imprime uma mensagem na tela.

};

#endif