#include<iostream>
#include<plus.h>

void plus::setA(int a)
{
    a_ = a;
}

void plus::setB(int b)
{
    b_ = b;
}

plus* plus::operator+(const plus& num)
{
    this->a_ += num.a_;
    this->b_ += num.b_;
    return this;
}

plus& plus::operator<<(std::string str)
{
    printf("%s\n", str.c_str());
    return *this;
}