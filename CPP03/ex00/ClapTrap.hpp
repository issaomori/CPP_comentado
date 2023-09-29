#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define MAX_HP 10
//defino o valor máximo de hp como 10.

class ClapTrap{
    //classe ClapTrap
    private:
    //atributos privados que só podem ser acessados pela própria classe.
    std::string name;
    int hp;
    int energy_points;
    int attack_damage;

    public:
    //métodos públicos que podem ser acessados por qualquer classe.
    ClapTrap(void);
    //construtor padrão que inicializa os atributos da classe.
    ~ClapTrap(void);
    //destrutor padrão.

    ClapTrap(std::string name);
    //construtor paramétrico que inicializa os atributos da classe. O construtor paramétrico é utilizado para inicializar um objeto com um valor específico.
    ClapTrap(ClapTrap const &name);
    //construtor de cópia que inicializa os atributos da classe. O construtor de cópia é utilizado para inicializar um objeto com os valores de outro objeto já existente.
    ClapTrap &operator=(ClapTrap const &name);
    //sobrecarga do operador de atribuição "=". A sobrecarga de operadores serve para definir o comportamento de um operador para um tipo de dado definido pelo usuário.

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

    void setName(std::string name);
    void setHitPoints(int hp);
    void setEnergyPoints(int energy_points);
    void setAttackDamage(int attack);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


};

#endif