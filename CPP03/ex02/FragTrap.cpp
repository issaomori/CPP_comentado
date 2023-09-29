#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
    // Aqui estamos definindo o construtor padrão da classe FragTrap que será usado para inicializar um objeto FragTrap sem nenhum argumento.
    // O construtor padrão está herdando o construtor padrão da classe base ClapTrap.
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->setName("FragTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    // Este é um construtor parametrizado que recebe um argumento do tipo std::string chamado name. Ele permite criar um objeto FragTrap com um nome específico.
    std::cout << "FragTrap " << this->getName() << " constucted"<< std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap(){
    //O destrutor da FragTrap é definido. Este destrutor é responsável por liberar qualquer recurso alocado durante a vida útil do objeto FragTrap. Neste caso, ele apenas imprime uma mensagem indicando que o destrutor da FragTrap foi chamado.
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &name) : ClapTrap(name){
    // Este é o construtor de cópia, usado para criar uma cópia de um objeto FragTrap existente.
    // Ele chama o construtor de cópia da classe base ClapTrap com o objeto passado como argumento.
    // Em seguida, copia os valores do objeto passado para o objeto atual (*this) e imprime uma mensagem.
    *this = name;
    std::cout << "FragTrap copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &name){
    // Este é o operador de atribuição de cópia, usado para copiar os valores de um objeto FragTrap existente para outro objeto FragTrap já inicializado.
    // Ele chama o operador de atribuição da classe base ClapTrap para copiar os valores relevantes.
    // Em seguida, retorna o próprio objeto atual.
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(name);
    return *this;
}

void FragTrap::highFivesGuys(void){
    // Este é um método da classe FragTrap chamado highFivesGuys.
    // Ele verifica se o objeto tem pontos de energia suficientes para dar um "high five". Se não tiver energia, ele imprime uma mensagem informando que o FragTrap está sem energia.
    // Se tiver energia, ele imprime uma mensagem indicando que o FragTrap quer dar um "high five" e reduz um ponto de energia.
    if (this->getEnergyPoints() <= 0){
        std::cout << "FragTrap " << this->getName() << " is without energy"<< std::endl;
        return;
    }
    std::cout << "FragTrap " << this->getName() << " want to give high five"<< std::endl;
    this->setEnergyPoints(getEnergyPoints() - 1);
}
