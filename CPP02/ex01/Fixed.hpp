#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

    private:
    int fixed_number_point;
    static const int fractional_bits = 8;

    public:
    Fixed();
    ~Fixed();

    //Construtor parametrizado, quando o compilador vai fazer a chamada ele confere qual deve ser chamado. Se for um int ele chama o de int, se for float ele chama o de float. Isso é chamado como overload de construtor. 
    Fixed(const Fixed &fixed);
    Fixed(const int number);
    Fixed(const float number);

    Fixed &operator = (const Fixed &fixed);
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator << (std::ostream &out, Fixed const &f);

#endif
