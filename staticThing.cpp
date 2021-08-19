#include<iostream>

using namespace std;

// static 在函数中状态的实现
void demo(){
    //函数中的静态变量
    static int count = 0;
    cout<< count << endl;
    count++;
}
void demo01(){
    int count = 0;
    cout << count <<endl;
    count++;
}
//2. static 在类对象中的实现
class Apple{
    public:
        static int i;
};
class Demo1{
    public:
        int i;
        Demo1(){
            cout << " this is demo1"<<endl;
        }
        ~Demo1(){
            cout << " this is the end of demo1" << endl;
        }
};
// 3. 在静态成员函数
class Demo2{
    public:
        int i;
        Demo2(){
            cout << " this is demo1"<<endl;
        }
        ~Demo2(){
            cout << " this is the end of demo1" << endl;
        }
        static void printMsg(){
            cout <<"Welcome to Demo2"<<endl;
        }
};

// 在使用static 之前内存只分配一次， 必须提前声明
int Apple::i = 1;
int main(){
    printf("\033[1;33m");
    cout << "static在函数中使用的时候，内存只分配一次空间，其他时候不将被分配， 这对于需要保存状态有用"<< endl;
    cout << " 使用静态变量的时候 : "<< endl;
    for(int i = 0; i < 10; i++){
        // 函数中使用静态变量
        demo();
    } 
    cout << " 不使用静态变量的时候 : "<< endl;
    for(int i = 0; i < 10; i++){
        // 函数中不使用静态变量
        demo01();
    }
    // class 中 static的演示
    //int Apple::i = 133;
    // 只能在 main 函数之前定义Apple::i
    Apple a; 
    Apple b;
    Apple c;
    a.i = 12;
    b.i = 13;
    c.i = 14;
    cout << "a.i : "<< a.i<<endl;
    cout << "b.i : "<< b.i<<endl;
    cout << "c.i : "<< c.i<<endl;

    int x = 0;
    cout <<"  statci对象"<< endl;
    if (x == 0){
        static Demo1 obj;
        static int test = 9;
        cout << " test = "<< test <<endl;
    }
    cout << "End of 第一个对象" << endl;
    cout <<" 非statci对象" <<endl;
    if (x == 0){
        // 放在循环体中，说明声明周期
        Demo1 obj1;
    }
    cout <<"End of 第二个对象"<<endl;
    cout <<" 可以看出static对象的声明周期为整个main"<< endl;
    cout <<" 类的静态成员函数"<<endl;
    Demo2::printMsg();
    cout <<" 类静态成员函数无法访问非静态成员"<<endl;
    return 0;
}
