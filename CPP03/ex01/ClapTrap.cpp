#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hp(10), energy_points(10), attack_damage(0){
    //constructor padrão, pois a forma canonica exige que tenha um construtor padrão.
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void){
    //destrutor padrão, pois a forma canonica exige que tenha um destrutor padrão.
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy_points(10), attack_damage(0){
    //construtor parametrizado, a inicialização ocorre após os dois pontos. Isso é chamado de lista de inicialização.
    //A lista de inicialização é a forma mais eficiente de inicializar variáveis de classe, pois ela evita que o compilador chame o construtor padrão e depois atribua um valor a variável.
    std::cout << "ClapTrap " << this->getName() << " constructed"<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &name){
    //construtor de cópia, pois a forma canonica exige que tenha um construtor de cópia. O construtor de cópia serve para copiar os valores de um objeto para outro. Por exemplo tenho um objeto A e quero copiar os valores dele para um objeto B. O construtor de cópia é chamado quando eu faço o seguinte:
    *this = name;
    //ClapTrap B = A;. O name carrega tudo que o objeto A tem, inclusive o nome.
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &name){
    //operador de atribuição, pois a forma canonica exige que tenha um operador de atribuição. O operador de atribuição serve para copiar os valores de um objeto para outro, porém o objeto já está inicializado também. Por exemplo tenho um objeto A e quero copiar os valores dele para um objeto B. E qual a diferença do operador de atribuição para o construtor de cópia? A diferença é que o operador de atribuição é chamado diretamente pelo programador, enquanto o construtor de cópia é chamado pelo compilador.
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->name = name.name;
    //pego o nome do objeto name e atribuo para o objeto que chamou o operador de atribuição.
    this->hp = name.hp;
    //pego o hp do objeto name e atribuo para o objeto que chamou o operador de atribuição.
    this->attack_damage = name.attack_damage;
    //pego o attack_damage do objeto name e atribuo para o objeto que chamou o operador de atribuição.
    this->energy_points = name.energy_points;
    //pego o energy_points do objeto name e atribuo para o objeto que chamou o operador de atribuição.
    return *this;
    //retorno o objeto que chamou o operador de atribuição.
}

std::string ClapTrap::getName(void) const{
    //método que retorna o nome do objeto.
    return this->name;
    //retorno o nome do objeto.
}

int ClapTrap::getHitPoints(void) const{
    //método que retorna o hp do objeto.
    return this->hp;
    //retorno o hp do objeto.
}

int ClapTrap::getEnergyPoints(void) const{
    //método que retorna o energy_points do objeto.
    return this->energy_points;
    //retorno o energy_points do objeto.
}

int ClapTrap::getAttackDamage(void) const{
    //método que retorna o attack_damage do objeto.
    return this->attack_damage;
    //retorno o attack_damage do objeto.
}

void ClapTrap::setName(std::string name){
    //método que atribui um nome ao objeto.
    this->name = name;
    //atribuo o nome ao objeto.
}

void ClapTrap::setHitPoints(int hp){
    //método que atribui um hp ao objeto.
    if (hp < 0)
    //se o hp for menor que 0, atribuo 0 ao hp.
        this->hp = 0;
    //atribuo 0 ao hp.
    this->hp = hp;
    //atribuo o hp ao objeto.
}

void ClapTrap::setEnergyPoints(int energy){
    //método que atribui um energy_points ao objeto.
    if (energy < 0)
    //se o energy_points for menor que 0, atribuo 0 ao energy_points.
        this->energy_points = 0;
    //atribuo 0 ao energy_points.
    this->energy_points = energy;
    //atribuo o energy_points ao objeto.
}

void ClapTrap::setAttackDamage(int attack){
    //método que atribui um attack_damage(dano de ataque) ao objeto.
    if (attack < 0)
    //se o attack_damage for menor que 0, atribuo 0 ao attack_damage.
        this->attack_damage = 0;
        //atribuo 0 ao attack_damage.
    this->attack_damage = attack;
    //atribuo o attack_damage ao objeto.
}

void ClapTrap::attack(const std::string& target){
    //método que ataca um alvo.

    if (target.empty()){
        //se o alvo estiver vazio, não ataca.
        std::cout << "ClapTrap " << getName() << " Cannot attack because there is no target" << std::endl;
        //imprimo na tela que não atacou porque não tem alvo.
        return;
    }
    if(this->getEnergyPoints() <= 0){
        //se o energy_points for menor ou igual a 0, não ataca.
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no EnergyPoints" << std::endl;
        //imprimo na tela que não atacou porque não tem energy_points.
        return;
    }
    else if (this->getHitPoints() <= 0){
        //se o hp for menor ou igual a 0, não ataca.
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no hp" << std::endl;
        //imprimo na tela que não atacou porque não tem hp.
        return;
    }
    else{
        //se não, ataca.
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"<< std::endl;
        //imprimo na tela que atacou.
        this->energy_points--;
        //decremento o energy_points.
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    //método que recebe dano.
    if (this->getHitPoints() == 0){
        //se o hp for igual a 0, não recebe dano.
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }
    else if (amount == 0)
    //se o dano for igual a 0, não recebe dano.
        std::cout << "ClapTrap " << this->getName() << " takes 0 damage" << std::endl;
    else
    //se não, recebe dano.
        std::cout << "ClapTrap " << this->getName() << 
    " takes " << amount << " damage" <<std::endl;
    //imprimo na tela que recebeu dano.
    if((int)amount >= getHitPoints())
    //se o dano for maior ou igual ao hp, o hp é zerado.
        this->setHitPoints(0);
        //atribuo 0 ao hp.
    else
        this->setHitPoints(getHitPoints() - amount);
        //subtraio o dano do hp.
}

void ClapTrap::beRepaired(unsigned int amount){
    //método que recupera hp.
    if (this->getHitPoints() == 0){
        //se o hp for igual a 0, não recupera hp.
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }else if (this->getEnergyPoints() < 1){
        //se o energy_points for menor que 1, não recupera hp.
        std::cout << "ClapTrap " << this->getName() << " cannot be repaired because it has no energy" << std::endl;
        return;
    }else
    //se não, recupera hp.
        std::cout << "ClapTrap " << this->getName() << " is repairing himself " << amount << " Hp"<< std::endl;
    if ( getHitPoints() > MAX_HP)
    //se o hp for maior que o máximo, o hp é setado para o máximo.
        setHitPoints(MAX_HP);
        //atribuo o máximo ao hp.
    this->setEnergyPoints(this->getEnergyPoints() -1);
    //decremento o energy_points porque recuperou hp.

}