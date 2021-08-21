#include<iostream>
using namespace std;


template<class T1>
T1 Max(T1 a, T1 b){
    return a >= b? a:b;
}
// 有时候，为了不引起误会， 可以将class 改为 typename
template<typename T>
T add(T a, T b)
{
    return a + b;
}

int main(int argc, char **argv){

    cout << "\033[0;45m";
    cout<<"int类型: \n";
    int maxNum = Max(123,45);
    cout<<"maxNum = Max(123,45) the max number is : "<< maxNum<< endl;
    //模板函数
    cout<<"char类型: \n";
    cout<<"Max(sada,13344) the max char is : "<< Max("sada","13344");
    cout <<"采用typenam关键字和class是一样的效果";
    cout <<" add(2,3)"<< add(2,3) << endl;
    
    return 0;
}
