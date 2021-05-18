#include "Int48.h"

Int48::Int48()
{
    mBytes[0] = 0 ;
    mBytes[1] = 0 ;
    mBytes[2] = 0 ;
    mBytes[3] = 0 ;
    mBytes[4] = 0 ;
    mBytes[5] = 0 ;
}

Int48::Int48(unsigned long long value)
{
    mBytes[0] =  ( value         & 0xff);
    mBytes[1] =  ((value >>  8)  & 0xff);
    mBytes[2] =  ((value >> 16 ) & 0xff);
    mBytes[3] =  ((value >> 24 ) & 0xff);
    mBytes[4] =  ((value >> 32 ) & 0xff);
    mBytes[5] =  ((value >> 40 ) & 0xff);
}

Int48 Int48::operator+(Int48 value)
{
    Int48 result ;
    unsigned long long myValue ;
    unsigned long long addValue;

    myValue = this->mBytes[5];
    myValue <<= 8 ;
    myValue |= this->mBytes[4];
    myValue <<= 8 ;
    myValue |= this->mBytes[3];
    myValue <<= 8 ;

    myValue = this->mBytes[2];
    myValue <<= 8 ;
    myValue |= this->mBytes[1];
    myValue <<= 8 ;
    myValue |= this->mBytes[0];


    addValue = value.mBytes[5];
    addValue <<= 8 ;
    addValue |= value.mBytes[4];
    addValue <<= 8 ;
    addValue |= value.mBytes[3];
    addValue <<= 8 ;

    addValue = value.mBytes[2];
    addValue <<= 8 ;
    addValue |= value.mBytes[1];
    addValue <<= 8 ;
    addValue |= value.mBytes[0];

    myValue += addValue;

    result = myValue;

    return result;
}

Int48 Int48::operator*(unsigned long long value)
{
    (*this) = (*this).value() * value;
    return (*this);
}

Int48 Int48::operator/(unsigned long long value)
{
    (*this) = (*this).value() / value;
    return (*this);
}

void Int48::operator=(unsigned long long value)
{
    mBytes[0] =  ( value         & 0xff);
    mBytes[1] =  ((value >>  8)  & 0xff);
    mBytes[2] =  ((value >> 16 ) & 0xff);
    mBytes[3] =  ((value >> 24 ) & 0xff);
    mBytes[4] =  ((value >> 32 ) & 0xff);
    mBytes[5] =  ((value >> 40 ) & 0xff);
}

void Int48::operator=(Int48 value)
{
    mBytes[0] = value.mBytes[0];
    mBytes[1] = value.mBytes[1];
    mBytes[2] = value.mBytes[2];
    mBytes[3] = value.mBytes[3];
    mBytes[4] = value.mBytes[4];
    mBytes[5] = value.mBytes[5];
}

Int48 &Int48::operator++()
{
    (*this) = (*this).value() + 1;
    return *this;
}

Int48 Int48::operator++(int)
{
    Int48 temp = (*this);
    ++(*this);
    return temp;
}

Int48 &Int48::operator--()
{
    (*this) = (*this).value() - 1;
    return *this;
}

Int48 Int48::operator--(int)
{
    Int48 temp = (*this);
    --(*this);
    return temp;
}

Int48::operator unsigned long long() const
{
    return value();
}

unsigned long long Int48::value() const
{
    unsigned long long retVal;

    retVal = this->mBytes[5];
    retVal <<= 8;
    retVal |= this->mBytes[4];
    retVal <<= 8;
    retVal |= this->mBytes[3];
    retVal <<= 8;

    retVal |= this->mBytes[2];
    retVal <<= 8;
    retVal |= this->mBytes[1];
    retVal <<= 8;
    retVal |= this->mBytes[0];

    return retVal;
}
