#include<iostream>
#include<string>
#include<plus.h>

int main(int argc, char *argv[])
{
    plus p(3,3);
    plus b(3,3);
    std::cout << "p = " << p.getReuslt()<< std::endl;
    plus* c = p + b;
    std::cout << "p + b = " << c->getReuslt() << std::endl;
    p<<"hello"<<"world";
    
    return 0;
}
