#include "ScavTrap.hpp"

//O ScavTrap é um porteiro que protege a entrada principal da fortaleza red belly. Ele é um dos guardas que precisa ser derrotado para que o jogador possa entrar na fortaleza.
int main() {
    ClapTrap clap("Mucilon");
    //defino um objeto clap da classe ClapTrap com o nome "Mucilon".
    //O ClapTrap inicializa com 10 pontos de energia, 10 pontos de hp e 0 pontos de ataque.
    ScavTrap scav("Ninho");
    //defino um objeto scav da classe ScavTrap com o nome "Ninho".
    //O ScavTrap inicializa com 50 pontos de energia, 100 pontos de hp, 20 pontos de ataque e o modo guardGate desativado.

    std::cout << std::endl;

    clap.attack(scav.getName());
    //o mucilon ataca o ninho.
    scav.takeDamage(clap.getAttackDamage());
    //o ninho recebe o dano de ataque do mucilon. Como eu herdei a classe ClapTrap na classe ScavTrap, o ataque do ScavTrap tem o mesmo dano de ataque do ClapTrap.
    scav.guardGate();
    //o ninho ativa o modo guardGate que serve para se proteger.
    std::cout << std::endl;

    scav.attack(clap.getName());
    //o ninho ataca o mucilon.
    clap.takeDamage(scav.getAttackDamage());
    //o mucilon recebe o dano de ataque do ninho que é 20, ou seja, o mucilon morre.
    scav.guardGate();
    //o ninho desativa o modo guardGate.
    scav.beRepaired(1);
    //o ninho se repara com 1 ponto de vida.
    std::cout << std::endl;

    clap.attack(scav.getName());
    //o mucilon ataca o ninho.
    scav.takeDamage(clap.getAttackDamage());
    //o ninho não recebe o dano de ataque do mucilon porque o mucilon morreu.
    scav.guardGate();
    //o ninho ativa o modo guardGate.
    scav.beRepaired(1);
    //o ninho se repara com 1 ponto de vida.
    std::cout << std::endl;

    clap.beRepaired(1);
    //o mucilon tenta se reparar com 1 ponto de vida, mas não consegue porque está morto.
    std::cout << std::endl;

    clap.attack(scav.getName());
    //o mucilon ataca o ninho.
    scav.takeDamage(clap.getAttackDamage());
    //o ninho não recebe o dano de ataque do mucilon porque o mucilon morreu.
    std::cout << std::endl;

    clap.beRepaired(10);
    //o mucilon tenta se reparar com 10 pontos de vida, mas não consegue porque está morto.
    std::cout << std::endl;

    return 0;
}
