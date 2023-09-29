#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
    {
    Weapon club = Weapon("crude spiked club");
    //cria uma arma do tipo Weapon com o nome "crude spiked club". O que é criado é um objeto do tipo Weapon que possui uma variável de membro chamada type que armazena o nome da arma. Crude spiked club significa clube com pontas afiadas.

    HumanA bob("Bob", club);
    //cria um humano do tipo HumanA com o nome "Bob" e arma "club". O que é criado é um objeto do tipo HumanA que possui uma variável de membro chamada _name que armazena o nome do humano e uma variável de membro chamada _weapon que armazena o tipo de arma do humano e tem um ponteiro para Weapon porque é uma referência. O construtor da classe HumanA recebe como parâmetro o nome do humano e a arma que ele vai usar. O construtor da classe HumanA inicializa as variáveis de membro da classe com os parâmetros passados.
    bob.attack();
    //faz o humano atacar
    club.setType("some other type of club");
    //muda o tipo de arma do humano
    bob.attack();
    //faz o humano atacar
    }
    {
    Weapon club = Weapon("crude spiked club");
    //cria uma arma do tipo Weapon com o nome "crude spiked club". O que é criado é um objeto do tipo Weapon que possui uma variável de membro chamada type que armazena o nome da arma. Crude spiked club significa clube com pontas afiadas.
    HumanB jim("Jim");
    //cria um humano do tipo HumanB com o nome "Jim". O que é criado é um objeto do tipo HumanB que possui uma variável de membro chamada _name que armazena o nome do humano e uma variável de membro chamada _weapon que armazena o tipo de arma do humano e tem um ponteiro para Weapon porque é uma referência. O construtor da classe HumanB recebe como parâmetro o nome do humano. O construtor da classe HumanB inicializa as variáveis de membro da classe com os parâmetros passados.
    // jim.setWeapon(club);
    // //muda o tipo de arma do humano
    jim.attack();
    //faz o humano atacar
    club.setType("some other type of club");
    //muda o tipo de arma do humano
    jim.attack();
    //faz o humano atacar
    jim.setWeapon(club);
    //muda o tipo de arma do humano
    jim.attack();
    //faz o humano atacar
    }
    return 0;
}
