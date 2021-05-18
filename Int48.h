#ifndef Int48_H
#define Int48_H

class Int48
{
public:
    Int48();
    Int48(unsigned long long value);

    Int48 operator+ (Int48 value);
    Int48 operator* (unsigned long long value);
    Int48 operator/ (unsigned long long value);

    void operator= (unsigned long long);
    void operator= (Int48 value);
    operator unsigned long long() const;

    // Declare prefix and postfix increment operators.
    Int48 &operator++();       // Prefix increment operator.
    Int48 operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    Int48 &operator--();       // Prefix decrement operator.
    Int48 operator--(int);     // Postfix decrement operator.

    unsigned long long value() const;

private:
    unsigned char mBytes[6];
};

#endif // Int48_H
