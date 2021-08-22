#include<iostream>
#include<memory>

using namespace std;
/*
int* const add_const(int a, int b){
    int c =(a+b);
    return &c;
}
const int* const_add(int a, int b){
    int c =(a+b);
    return &c;
}
*/
int add(const int &a,const int &b) 
{
    return a + b;
}
int main(int argc, char **argv){
    if(1){
        const int test = 1;
    }
    //cout << test;
    printf("\033[1;33m");
    printf("const的基本用法1： 修饰一些常量及数组\n");
    printf("比如： const int num = 13， 则 num 的数值无法被修改\n");
    printf("const用法2 ： 修饰指针变量* 及引用变量 & \n");
    int a;
    int *aPtr;
    a = 5;
    aPtr = &a;
    cout<<"aPtr的地址为: "<<aPtr<<endl;
    cout<<" a = "<< a << endl << " *aPtr = "<< *aPtr <<endl;
    *aPtr = 55;
    cout<<" a = "<<a<<endl;
    cout<<"注意，在这里const修饰函数中的参数常用于 参数为 指针 或者是 引用的情况下， 这样保护了原参数不被修改"<<endl;
    cout<<" 下面是 const int* 的用法" << endl;
    int b = 2;
    const int* c = &a;
    cout<<"c 的地址为: "<< &c <<endl << "c = "<< *c<<endl;
    c = &b;
    cout<<"a 的地址为： "<< &a << endl<< "a = "<< a<<endl;
    cout<<"b 的地址为： "<< &b << endl<< "b = "<< b<<endl;
    cout<<"c 的地址为： "<< &c << endl<< "c = "<< *c<<endl;
    cout<<" 下面是 const int* const 的用法: "<<endl;
    int* const cPtr = &a;
    cout<<"注意的是： 这里的意思是指针的地址是无法被修改的，如果是cosnt修饰了cPtr的话， cPtr指向的内容也无法改变"<<endl;
    cout<<"修改前 cPtr地址为："<<cPtr << "*cPtr = "<< *cPtr;
    *cPtr = b;
    cout<<"修改后 cPtr地址为："<<cPtr << "*cPtr = " << *cPtr;
    const int n = 100;
    cout<<"n: "<<n<<endl;
    cout<<" 小结： const int * 或者 int cosnt* 指针所指向的内容不变， int *const 指针本身不可变";
    cout<<" 用法三： 应用到函数中"<<endl;
    cout<<" 用于修饰参数"<<endl;
    int num = add(34,434);
    cout<<"add(34,434) = "<< num <<endl;
    cout<<" 1.对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const 引用传递”，目的是提高效率。例如将void func(A a) 改为void func(const A &a)。";
    cout<<"2.对于内部数据类型的输入参数，不要将“值传递”的方式改为“const 引用传递”。否则既达不到提高效率的目的，又降低了函数的可理解性。例如void func(int x) 不应该改为void func(const int &x)。";
    return 0;
}
