#include<iostream>

using namespace std;

int main(){
    // 1. 指针的概念
    // 2. const 和 指针 的关系
    // 3. 二级指针
    // 4. char* 和 char [] 和 char** 的区别
    // 5. 野指针
    //      - 没有初始化的指针，可能指向的地址为非法访问的，没有办法操作， 程序崩溃
    //      - 随即指向， 可能指向了 别的指针指向的地址 程序无法找错
    //      - 注意： 指针要初始化!!!!!
    //      - 空指针： NULL(避免野指针)
    cout << "\033[1;33m"<<endl;
    int a = 10;
    int b = 12;
    cout << " &a = " << &a << endl;
    cout << " &b = " << &b << endl;
    int* ptr = &a;
    cout << " ptr = " << ptr << endl;
    *ptr = b;
    cout << " ptr = " << ptr << endl;
    cout << a << endl;

    char strHelloWorld[] = {"strhellowordl"};
    char* ptrHelloWorld = "ptr";
    cout << "sizeof(strHelloWorld)"  << sizeof(strHelloWorld) << endl;
    cout << "sizeof(ptrHelloWorld)"  << sizeof(ptrHelloWorld) << endl;
    ptrHelloWorld = strHelloWorld;
    cout << ptrHelloWorld  <<endl;
    cout << *ptrHelloWorld << endl; 
    cout << "----------------" << endl;
    cout << "关于char* char** char[]"<< endl;
    char* hello = "hello";
    char** twoPtr = &hello;
    cout << hello[2] << endl;
    cout << "twoPtr[2]: " << twoPtr[0] << endl;
    cout << "结果如下："<< endl;
    cout << "char* = string = char []" << endl;
    cout << "char** = string[] = char [][]" << endl;
    cout << "-----------------" << endl;
    // 一般来说char ** 这种写法是二级指针， 也就是说它的右值是地址
    char* A[] = {"hello","world"};
    char** AA = A;
    cout << "---------------------" << endl;
    cout << "指针操作& *" << endl;
    cout << "指针操作 -- ++" << endl;
    cout << "sp++ 和 ++sp 的区别" << endl;
    cout << "char* cp2 = ++cp这句代码的汇编语言及其含义：" << endl;
    cout << "++sp 首先将sp的信息发送到寄存器当中，寄存器完成+1的操作，然后写回到sp中,  将sp内容写到寄存器， 然后将寄存器复制到sp2" << endl;
    cout <<"char* cp2 = cp++:" << endl;
    cout << "与++sp不同， sp++直接将sp的值首先给到sp2，然后再将sp的数值给到寄存器， 寄存器进行+1操作，最后返回给sp" << endl;
    cout << " 总结： 由上可知： b1 = ++a 和 b2 = a++ 中 b1取的数值是++后的， 而b2的数值是a++前的" << endl;
    // test 
    int a_ = 1;
    int b1 = a_ ++; // b1 = a = 1;
    int b2 = ++ a_; // b2 = a+1+1=3;
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    cout << "cp-- 和 --cp 一样" << endl;
    cout << "ps: ++sp 和 sp++ 无法作为左值 因为 只是一个副本"  << endl;
    cout << "*++sp 和 *sp++ 是可以作为左指的" << endl;
    cout << "test" << endl;
    char i = 'i';
    char bb = 'b';
    char* test_ = "abcd";
    //*++test_ = i;
    //*test_++ = bb;
    cout << "*test_++ = " << *test_++ << endl;
    cout << "*++test_ = " << *++test_ << endl;
    cout << "test_ = "  << test_ << endl;
    cout << "---------------------" << endl;
    cout << " 关于++++,----等符号"  << endl;
    cout << "处理过程为贪心算法， 一个字符一个字符读取， 直到不是一个运算" << endl;

    int arry[3] = {1,2,3};
    int* ptr_arry = arry;
    for(int i = 0; i < 3; i++)
    {
        printf("arry[%d] = %d\n", i, arry[i]);
    }
    cout << "arry = " << arry << endl;
    cout << "ptr_arry = " << ptr_arry << endl;
    cout << "&ptr_arry = " << &ptr_arry << endl;
    cout << "ptr_arry[2] = " << ptr_arry[2] << endl;

    return 0;
}
