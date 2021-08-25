#include<iostream>
#include<string.h>
#include<vector>
#define YELLOW() \
    printf("\033[1:33m") \

// #define INT_TEST  false
// #define RED(



using namespace std;
class Person;

template<class T>
// struct data{
//     T data; // 数据区域
//     int num; // 维护其长度
// };
class xsb{
    private:
        T* arrptr_;
        int num_;
        int cap_;

    public:
        // \brief: This is a simple structure funciton
        // \paraments: num is the number of the arry 
        xsb(const int cap)
        {
            cap_ = cap;
            num_ = 0;
            //分配空间
            arrptr_ = new T[num_];
            cout << "initialize successed!" << endl;
        }
        // 在最后添加元素
        bool push_back(const T& data)
        {
            if(num_ >= cap_)
            {
                return false;
            }
            else
            {
                arrptr_[num_] = data;
                num_ += 1;
                return true; 
            }
        }

        T getElem(const int num) const
        {
            return arrptr_[num-1];
        }

        bool erea(const int num)
        {
            if(0 > num && num >= num_)
            {
                return false;
            }
            else
            {
                for(int i = num; i < num_;i++)
                {
                    //  往前移动
                    arrptr_[i-1] = arrptr_[i];
                }
                num_ -= 1;
                return true;
            }
        }

        bool modify(const int num,const T& data)
        {
            if(num< 0 || num > num_)
            {
                return false;
            }
            else
            {
                arrptr_[num-1] = data;
                return true;
            }
        }

        bool add(const int num,const T& data)
        {
            if(num < 0 || num >num_)
            {
                return false;
            }
            else
            {
                // 存储num处的data
                for(int i = num_;i > num ; i--)
                {
                    arrptr_[i] = arrptr_[i-1];
                }
                arrptr_[num] = data;              
                num_ += 1;
                return true;
            }
        }

        void showElem()
        {
            cout << "printing......" << endl;
            for(int i = 0; i < num_; i++)
            {
                cout << "xsb[" << i << "] = " << arrptr_[i] << endl;
            } 
        }

        // 访问内部
        int getNum()
        {
            return num_;
        }

        int getCap()
        {
            return cap_;
        }

        T* getArryPtr()
        {
            return arrptr_;
        }

        T& get(const int num)
        {
            return arrptr_[num-1];
        }

        ~xsb()
        {
            if(arrptr_ != nullptr)
            {
                delete[] arrptr_;
                arrptr_ = nullptr;
            }
        }
};

///////////////////////测试用clas///////////////////////
class Person{
    public:
        int age;
        string name;
        double height;
        double weight;
        

        Person(){}
        Person(const string name, const int age)
        {
            this->name = name;
            this->age = age;
        }

};


int main(int argc, char const *argv[])
{
    
    #if INT_TEST
    cout << "============TEST OF THE 顺序表(arry版本)[INT]=================" << endl; 
    xsb<int> s(10);
    cout << "test: push_back() :"  << endl;
    for(int i = 0; i < 11; i++)
    {
        bool flag = s.push_back(i);
        cout << ( flag? "完成": "失败" ) << endl;
    }
    s.showElem();
    cout << "当前顺序表中的元素个数    xsb<Person> p(4);
" << s.getNum() << endl;


    cout << "测试删除:" << endl;
    bool flag = s.erea(1);
    cout << "操作: " << (flag? "成功" : "失败") << endl;
    cout << "设定删除第一个元素" << endl;
    s.showElem();
    cout << "当前顺序表中的元素个数" << s.getNum() << endl;
    
    cout << "测试修改" << endl;
    flag = s.modify(5,1999);
    cout << "操作: " << (flag? "成功" : "失败") << endl;
    cout << "修改第五个元素为1999" << endl;
    s.showElem();
    cout << "当前顺序表中的元素个数" << s.getNum() << endl;


    cout << "测试增加" << endl;
    flag = s.add(4,14);
    cout << "操作: " << (flag? "成功" : "失败") << endl;
    cout << "在第4个元素后面添加14" << endl;
    s.showElem();
    cout << "当前顺序表中的元素个数" << s.getNum() << endl;

    cout << "测试查找" << endl;
    for(int i = 1;i < s.getNum()+1; i++)
    {测试
        cout << "第" << i << "个元素为: " << s.get(i) << endl;
    }
    cout << *s.getArryPtr()  << endl;
    #else
    cout << "test of 自定义" << endl;
    Person p1("person1",1);
    Person p2("person2",2);
    Person p3("person3",3);
    Person p4("person4",4);
    xsb<Person> p(10);
    // bool flag = p.push_back(p4);
    // p.push_back(p2);
    // p.push_back(p1);
    // p.add(0,p1);
    // p.add(1,p2);
    for(int i = 1; i <= p.getNum(); i++)
    {
        cout << p.get(i).name << endl;
    }
    // cout << "测试增加" << endl;
    // flag = p.add(1,p4);
    // cout << "操作: " << (flag? "成功" : "失败") << endl;
    // cout << "当前顺序表中的元素个数" << p.getNum() << endl;
    
    // Person* pp = new Person[2];
    // pp[0] = p1;
    // pp[1] = p2;
    vector<Person> p1;
    #endif
    return 0;
}
