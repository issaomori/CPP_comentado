#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
    const Animal* j = new Dog();
    //crio um animal do tipo Dog
    const Animal* i = new Cat();
    //crio um animal do tipo Cat

    delete j;
    delete i;

    std::cout << "---------------------------------------- " << std::endl;
    Dog basic;
    //crio um animal do tipo Dog
    std::string    dogIdeas[100] = {"play", "ball", "run", "eat", "play", "sleep", "play"};
    //crio um array de 100 strings que serve para armazenar as ideias do cérebro do animal

    for(int i = 0; i < 7; i++)
    //enquanto não chegar no fim das ideias do animal
        basic.getBrain()->setIdea(dogIdeas[i], i);
        //vou colocando as ideias do animal no array de ideias dele
    {
        Dog tmp = basic;
        //crio um animal temporário do tipo Dog que recebe as ideias do animal basic
    }
    std::cout << "Dog's ideas: ";
    for(int i = 0; i < 7; i++)
    //enquanto não chegar no fim das ideias do cachorro
        std::cout << basic.getBrain()->getIdea(i) << " ";
        //imprimo na tela as ideias do cachorro
    std::cout << std::endl;

    std::cout << "---------------------------------------- " << std::endl;
    const Animal* animals[6] = { new Dog(), new Dog(), new Cat(), new Cat(), new Dog(), new Cat() };
    //crio um array de 6 animais que recebe 3 cachorros e 3 gatos
    for (int i = 0; i < 6; i++) {
        //enquanto não chegar no fim do array de animais
        animals[i]->makeSound();
        //imprimo na tela o som que o animal faz
        delete animals[i];
        //deleto o animal
    }

    std::cout << "---------------------------------------- " << std::endl;
    Cat* cat = new Cat();
    //crio um animal do tipo Cat
    cat->getBrain()->setIdea("Idea 1", 0);
    //coloco a ideia "Idea 1" no índice 0 do array de ideias do animal
    cat->getBrain()->setIdea("Idea 2", 1);
    //coloco a ideia "Idea 2" no índice 1 do array de ideias do animal

    Cat* cat2 = new Cat();
    //crio um animal do tipo Cat
    *cat2 = *cat;
    //o animal cat2 recebe as ideias do animal cat que foram copiadas pelo operador de atribuição sobrecarregado do cat ja existente

    std::cout << "---------------------------------------- " << std::endl;
    std::cout << "Cat1 Brain Ideas: " << cat->getBrain()->getIdea(0) << ", " << cat->getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 Brain Ideas: " << cat2->getBrain()->getIdea(0) << ", " << cat2->getBrain()->getIdea(1) << std::endl;

    delete cat;
    delete cat2;

    return 0;
}
