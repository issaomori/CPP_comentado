#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *brain;
    public:
        Dog(void);
        ~Dog(void);

        Dog(Dog const &name);
        Dog &operator=(Dog const &name);

        void makeSound(void) const;
        Brain *getBrain() const;
};
#endif