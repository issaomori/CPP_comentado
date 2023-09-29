#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
    //O construtor padrão da ScavTrap é definido. Este construtor chama o construtor padrão da classe base ClapTrap para garantir que os membros herdados da classe base sejam inicializados corretamente. Em seguida, ele inicializa alguns atributos específicos da ScavTrap, como nome, pontos de vida (hp), pontos de energia (energy_points) e dano de ataque (attack_damage) com valores específicos.
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->setName("ScavTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    //O construtor parametrizado da ScavTrap também é definido. Este construtor chama o construtor parametrizado da classe base ClapTrap com o nome fornecido como argumento. Em seguida, ele inicializa os mesmos atributos específicos da ScavTrap que o construtor padrão, como pontos de vida, pontos de energia e dano de ataque.
    std::cout << "ScavTrap " << this->getName() << " constructed"<< std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(void){
    // O destrutor da ScavTrap é definido. Este destrutor é responsável por liberar qualquer recurso alocado durante a vida útil do objeto ScavTrap. Neste caso, ele apenas imprime uma mensagem indicando que o destrutor da ScavTrap foi chamado.
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &name){
    // O operador de atribuição da ScavTrap é definido. Este operador de atribuição permite copiar os valores de um objeto ScavTrap para outro objeto ScavTrap. Ele chama o operador de atribuição da classe base ClapTrap para copiar os membros herdados (nome, pontos de vida, pontos de energia e dano de ataque) e, em seguida, copia os atributos específicos da ScavTrap.
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->setName(name.getName());
    this->setHitPoints(name.getHitPoints());
    this->setAttackDamage(name.getAttackDamage());
    this->setEnergyPoints(name.getEnergyPoints());
    return *this;
}

void ScavTrap::attack(const std::string& target){
    // O método attack da ScavTrap sobrescreve o método attack da classe base ClapTrap. Ele adiciona uma verificação para verificar se o alvo está vazio e se o ScavTrap tem energia suficiente e pontos de vida para atacar. Se todas as condições forem atendidas, o ScavTrap realiza o ataque e reduz sua energia.

    if (target.empty()){
        std::cout << "ScavTrap " << getName() << " Cannot attack because there is no target" << std::endl;
        return;
    }
    if(this->getEnergyPoints() <= 0){
        std::cout << "ScavTrap " << getName() << " Cannot attack because it has no EnergyPoints" << std::endl;
        return;
    }
    else if (this->getHitPoints() <= 0){
        std::cout << "ScavTrap " << getName() << " Cannot attack because it has no hp" << std::endl;
        return;
    }
    else{
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"<< std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
}

void ScavTrap::guardGate(void){
    // O método guardGate da ScavTrap é um novo método específico da ScavTrap. Ele verifica se o ScavTrap está morto (sem pontos de vida) e imprime uma mensagem apropriada. Caso contrário, ele indica que o ScavTrap está em modo de guarda.
    if (this->getHitPoints() <= 0)
        std::cout << "ScavTrap " << this->getName() << " can't guard gate because he's dead" << std::endl;
    else
        std::cout << "ScavTrap " << this->getName() << " is currently in gate keeper mode" << std::endl;
}

// Em resumo, a ScavTrap herda os atributos e métodos da classe base ClapTrap e estende a funcionalidade adicionando métodos específicos, como guardGate. A herança permite que você reutilize o código da classe base, evitando a duplicação de código e facilitando a manutenção.