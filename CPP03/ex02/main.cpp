#include "FragTrap.hpp"

//O FragTrap é um ClapTrap reprogramado por "handsome Jack" para ser um papel de combate ativo. Ele é um dos personagens jogáveis ​​em Borderlands: The Pre-Sequel. Ou seja uma evolução do ClapTrap.
int main() {
    ClapTrap clap("Red da Grota");
    //defino um objeto clap da classe ClapTrap com o nome "Red da Grota".
    //O ClapTrap inicializa com 100 pontos de energia, 100 pontos de hp e 30 pontos de ataque.
    ScavTrap scav("Dr. Gutierrez");
    //defino um objeto scav da classe ScavTrap com o nome "Dr. Gutierrez".
    //O ScavTrap inicializa com 50 pontos de energia, 100 pontos de hp, 20 pontos de ataque e o modo guardGate desativado.
    FragTrap frag("Paulo Plinio");
    //defino um objeto frag da classe FragTrap com o nome "Paulo Plinio".
    //O FragTrap inicializa com 100 pontos de energia, 100 pontos de hp, 30 pontos de ataque.

    std::cout << std::endl;

    clap.attack(scav.getName());
    //o Red da Grota ataca o Dr. Gutierrez.
    scav.takeDamage(clap.getAttackDamage());
    //o Dr. Gutierrez recebe o dano de ataque do Red da Grota que é 30, então fica com 70 de hp.
    scav.guardGate();
    //o Dr. Gutierrez ativa o modo guardGate que serve para se proteger.
    scav.beRepaired(1);
    //o Dr. Gutierrez se repara com 1 ponto de vida (71).

    std::cout << std::endl;

    scav.attack(clap.getName());
    //o Dr. Gutierrez ataca o Red da Grota.
    clap.takeDamage(scav.getAttackDamage());
    //o Red da Grota recebe o dano de ataque do Dr. Gutierrez que é 20, ou seja, o Red da Grota fica com 80 de hp.
    scav.guardGate();
    //o Dr. Gutierrez desativa o modo guardGate.
    scav.beRepaired(1);
    //o Dr. Gutierrez se repara com 1 ponto de vida (72).

    std::cout << std::endl;

    clap.attack(scav.getName());
    //o Red da Grota ataca o Dr. Gutierrez.
    scav.takeDamage(clap.getAttackDamage());
    //o Dr. Gutierrez recebe o dano de ataque do Red da Grota que é 30, então fica com 42 de hp.
    scav.guardGate();
    //o Dr. Gutierrez ativa o modo guardGate.
    scav.beRepaired(1);
    //o Dr. Gutierrez se repara com 1 ponto de vida (43).

    std::cout << std::endl;

    frag.attack(clap.getName());
    //o Paulo Plinio ataca o Red da Grota.
    clap.takeDamage(frag.getAttackDamage());
    //o Red da Grota recebe o dano de ataque do Paulo Plinio que é 30, então fica com 50 de hp.
    frag.highFivesGuys();
    //o Paulo Plinio faz um high five.

    std::cout << std::endl;

    clap.attack(frag.getName());
    //o Red da Grota ataca o Paulo Plinio.
    frag.takeDamage(clap.getAttackDamage());
    //o Paulo Plinio recebe o dano de ataque do Red da Grota que é 30, então fica com 70 de hp.
    frag.highFivesGuys();
    //o Paulo Plinio faz um high five.

    std::cout << std::endl;

    return 0;
}
