#include<iostream>
using namespace std;


template<class T1>
T1 Max(T1 a, T1 b){
    return a >= b? a:b;
}

int main(int argc, char **argv){

    cout<<"int类型: \n";
    int maxNum = Max(123,45);
    cout<<"the max number is : "<< maxNum<< endl;
    //模板函数
    cout<<"char类型: \n";
    cout<<"the max char is : "<< Max("sada","13344");
    
    return 0;
}
