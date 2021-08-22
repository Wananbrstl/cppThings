#include <iostream>
#include <memory>
#include <string>

using namespace std;
int main()
{
    cout << "================ 案例1 auto_ptr ==============" << endl;
    // 创建了一个string的auto_ptr智能指针 指向了 五个string类型的智能指针
    auto_ptr<string> language[5] = {
    auto_ptr<string>(new string("c++")),
    auto_ptr<string>(new string("c")),
    auto_ptr<string>(new string("java")),
    auto_ptr<string>(new string("c#")),
    auto_ptr<string>(new string("python")),
    };
    cout << "--------the first print---------" << endl;
    for(int i = 0; i < 5; ++i)
    {
        cout << *language[i] << endl;
    }
    // 假设现在有另外一个智能指针指向了其中的c++
    auto_ptr<string> cpp_ptr;
    cpp_ptr = language[4];
    // 权限交给了cpp_ptr
    cout << "--------the second print---------" << endl;
    for(int i = 0; i < 4; ++i)
    {
        cout << *language[i] << endl;
    }
    cout << "此时, cpp_ptr = " << *cpp_ptr << endl;
    cout << "假如有另外一个指向相同的空间， 则之前的作废" << endl;
    
    
    // test2
    cout << "================== 案例2 unique_ptr ==================" << endl;
    int* ptr_A = new int(10);
    unique_ptr<int> unique_ptr_A = unique_ptr<int>(ptr_A);
    cout << "*unique_ptr_A = " << *unique_ptr_A << endl;
    // 假如另外一个也指向这个空间的话， 则回报错
    unique_ptr<int> unique_ptr_B;
    // unique_ptr_B = unique_ptr_A; 报错
    // unique_ptr_B = ptr_A;  同上
    cout << "unique_ptr只能一个指向另外一个地址，如果想转移权限， 可以使用move "<< endl;
    unique_ptr_B = move(unique_ptr_A);
    // cout << "*unique_ptr_A = " << *unique_ptr_A << endl;(已经销毁，报错)
    cout << "*unique_ptr_B = " << *unique_ptr_B << endl;


    cout << "================== 案例3 shared_ptr ==================" << endl;
    int* ptr_C = new int(19);
    shared_ptr<int> sharedPtrA = shared_ptr<int>(ptr_C);
    {cout << " 一个指针指向了ptr_C " << endl;
    auto sharedPtrB = sharedPtrA;
    cout << ((sharedPtrA.get() != nullptr) ? *(sharedPtrA) : -1 ) << endl;
    cout << ((sharedPtrB.get() != nullptr) ? *(sharedPtrB) : -1 ) << endl; 
    cout << "此时， sharedPtrA计数为:  " << sharedPtrA.use_count() << endl;
    cout << "此时， sharedPtrA计数为:  " << sharedPtrA.use_count() << endl;
    // cout << "此时， weakPtrB计数为:  " << weakPtrB.use_count() << endl;
    }
    cout << "退出了sharePtrB的作用区!" << endl;
    cout << "此时， sharedPtrA计数为:  " << sharedPtrA.use_count() << endl;
    
    cout << "============== 案例4 shared_ptr + weak_ptr ==============" << endl;
    cout << "创建weakPtrA 之前的计数为:   " << sharedPtrA.use_count() << endl;
    weak_ptr<int> weakPtrA = sharedPtrA;
    cout << "创建weakPtrA 之后的计数为:   " << sharedPtrA.use_count() << endl;
    return 0;
}