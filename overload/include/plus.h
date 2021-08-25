#ifndef PLUS_H
#define PLUS_H

#include <iostream>
class plus{
public:
    plus(){}
    plus(int a, int b):a_(a), b_(b){}

    void setA(int a);
    void setB(int b);

    // overload
    plus* operator +(const plus& num);
    plus& operator<<(std::string str);
    
    // plus& operator<<();
    int getReuslt()
    {
        result_ = a_ + b_;
        return result_;
    }

private:
    int a_;
    int b_;
    int result_;
};

#endif
