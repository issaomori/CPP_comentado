#include "ClapTrap.hpp"

// int	main(void)
// {
// 	ClapTrap	trap1;
// 	ClapTrap	trap2;

// 	trap1.setName("Rei Arthur");
//     trap2.setName("D. Sebastião");
// 	trap1.setAttackDamage(15);
// 	trap1.attack(trap2.getName());
// 	trap2.takeDamage(trap1.getAttackDamage());
// 	trap1.setAttackDamage(120);
// 	trap2.takeDamage(trap1.getAttackDamage());
	
// }

//O ClapTrap é um robô de uso geral muito entusiasmado, mas covarde.
int main(void) {
  ClapTrap temp2("Supla");
  //defino um objeto temp2 da classe ClapTrap.
  ClapTrap clap1("Gianechini"), clap2(temp2);
  //defino dois objetos da classe ClapTrap, clap1 e clap2, e inicializo clap1 com o nome "Gianechini" e clap2 com o nome de temp2 que é "Supla".

  std::cout << std::endl;

  clap1.setAttackDamage(1);
  //seto o attack_damage de clap1 para 1, ou seja, o dano de ataque de clap1 será 1.
  clap2.setAttackDamage(1);
  //seto o attack_damage de clap2 para 1, ou seja, o dano de ataque de clap2 será 1.

  clap1.attack(clap2.getName());
  //O Giannecchini ataca o Supla.
  clap2.takeDamage(clap1.getAttackDamage());
  //O Supla recebe o dano de ataque do Giannecchini.
  clap2.beRepaired(1);
  //O Supla se repara com 1 ponto de vida.
  std::cout << std::endl;

  clap2.attack(clap1.getName());
  //O Supla ataca o Giannecchini.
  clap1.takeDamage(clap2.getAttackDamage());
  //O Giannecchini recebe o dano de ataque do Supla.
  clap2.beRepaired(1);
  //O Supla se repara com 1 ponto de vida.
  std::cout << std::endl;

  clap1.setAttackDamage(10);
  //aumento o attack_damage do objeto clap1 para 10.
  clap2.setAttackDamage(10);
  //aumento o attack_damage do objeto clap2 para 10.

  clap1.attack(clap2.getName());
  //O Giannecchini ataca o Supla.
  clap2.takeDamage(clap1.getAttackDamage());
  //O Supla recebe o dano de ataque do Giannecchini.
  clap2.beRepaired(1);
  //O Supla se repara com 1 ponto de vida. Porém, o Supla morre pois o dano de ataque do Giannecchini é 10 e isso mata-o.

  //esse loop serve para ele se reparar até gastar todos os pontos de energia.
  for (int i = 0; i < 8; i++) {

    clap1.beRepaired(1);
    //O Giannecchini se repara com 1 ponto de vida.
  }

  std::cout << std::endl;

  clap1.attack(clap2.getName());
  //O Giannecchini ataca o Supla.
  clap2.takeDamage(clap1.getAttackDamage());
  //O Supla recebe o dano de ataque do Giannecchini.
  clap2.attack(clap1.getName());
  //O Supla ataca o Giannecchini.

  std::cout << std::endl;

  clap1.beRepaired(10);
  //reparo o objeto clap1 com 10 pontos de vida.
  clap2.beRepaired(10);
  //reparo o objeto clap2 com 10 pontos de vida.

  std::cout << std::endl;

  return (0);
}
