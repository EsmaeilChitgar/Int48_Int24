#ifndef INT24_H
#define INT24_H

class Int24
{
public:
    Int24();
    Int24(unsigned long);

    Int24 operator+ (Int24 value);
    Int24 operator* (int value);
    Int24 operator/ (int value);

    void operator= (unsigned long value);
    void operator= (Int24 value);
    operator int() const;


    // Declare prefix and postfix increment operators.
    Int24 &operator++();       // Prefix increment operator.
    Int24 operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    Int24 &operator--();       // Prefix decrement operator.
    Int24 operator--(int);     // Postfix decrement operator.

    unsigned long value() const;

private:
    unsigned char mBytes[3] ;
};

#endif // INT24_H
