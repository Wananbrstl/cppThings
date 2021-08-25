#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class myArry{
private:
    //需要存放数组的指针
    T* arryPtr_;
    //维护数组的容量
    int cap_;
    //维护数组的大小
    int num_;

public:
    myArry(int cap): num_(0), cap_(cap)
    {
        // 开辟空间
        arryPtr_ = new T[cap_];
        cout << "初始化完成....，当前arryPtr地址为: " << arryPtr_ << endl;
    }
    void push_back(const T& elem)
    {
        if(num_ >= cap_)
        {
            cout << "容量太小了" << endl;
            cout << "正在创建新的数组"  << endl;
            cap_ *= 2;
            T* newArryPtr = new T[cap_];
            for(int i = 0; i < num_; i++)
            {
                newArryPtr[i] = arryPtr_[i];
            }
            delete[] arryPtr_;
            arryPtr_ = newArryPtr ;
            cout << "重新分配一个大的空间， 此时arryptr地址为: " << arryPtr_<< endl;
            cout << "元素复制成功"  << endl;
        }
        arryPtr_[num_] = elem;
        ++num_;
        cout<< "添加成功"<< endl;
    }
    
    bool delete_back()
    {
       if(num_ == 0)
       {
           cout << "没有元素" << endl;
           return false;
       }
       num_ --;
       cout << "删除成功" << endl;
       
    }
    // 获取元素
    bool getElem(int num,T& elem)
    {
        if(num > num_)
        {
            cout << "访问的元素不存在"  << endl;
            return false;
        }
        elem = arryPtr_[num-1];
        return true;
    }

    int getNum()
    {
        return num_;
    }
    int getCap()
    {
        return cap_;
    }
    T operator[](int num)
    {
        T temp;
        this->getElem(num+1,temp);
        return temp;
    }
    
       
    
};

int main()
{
    cout << "--------------TEST OF INT-------------"<< endl;
    myArry<int> arry(10);
    cout << "cap of arry is " << arry.getCap() << endl;
    cout << "num of arry is " << arry.getNum() << endl;
    arry.push_back(10);
    cout << "num of arry is " << arry.getNum() << endl;
    int a;
    arry.getElem(1,a);
    cout << "getELem = "<< a << "   " << "arry[0] =  " << arry[0] <<  endl;
    for(int i = 0; i < 11; i++)
    {
        arry.push_back(i);
    }

    for(int i = 0; i<12;i++)
    {
        cout << "arry_" << i << " = " << arry[i] << endl;
    }
    cout << "--------------TEST OF STRING-------------"<< endl;
    myArry<string> stringarry(10);
    stringarry.push_back("hello worlld");
    cout << stringarry[0] << endl;
    return 0;
}

