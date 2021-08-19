#include<iostream>
using namespace std;

inline int swap(int num1, int num2){
    return num1 + num2;
}
int main(){

    cout << "学习内连函数"<< endl;
    cout << "内链函数inline类似于宏定义， 代码在执行前，编译器将inline函数替换成那个函数的执行代码";    
    int num = swap(2,4);
    return 0;
}
