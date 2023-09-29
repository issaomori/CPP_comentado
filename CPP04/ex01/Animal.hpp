#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;

    public:
        Animal(void);
        virtual ~Animal(void);

        Animal(const Animal &name);
        Animal(std::string const type);
        Animal &operator=(const Animal &name);

        std::string getType(void) const;
        void setType(std::string type);
        virtual void makeSound(void) const;
};

#endif
