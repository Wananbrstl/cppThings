#include <iostream>

using namespace std;
int main()
{
    cout << "一般来说 除以2 的运算 通过运算符 / 即可得到结果 但是这样会损失信息"  << endl;
    cout << "除法的使用: "<<endl;
    int a = 199;
    int b = 122;
    cout << "标准除法 (a+b)/2 = " << (a+b)/2 <<endl;
    int c = ((a ^ b) >> 1) + (a & b);
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    cout << " 非标准除法： (a ^ b) >> 1 + (a & b) = " << c << endl;
    return 0;
}

