#include<iostream>
#include<string.h>
using namespace std;

template<class T>
struct single_list_node
{
    struct single_list_node<T>* next;
    T data;
};

template<class T>
class List
{
private:
    // 头尾指针
    struct single_list_node<T>* head_;
    struct single_list_node<T>* end_;
public:
    List()
    {
        head_ = new struct single_list_node<T>;
        end_ = head_;
    }

    ////////////////////////////// 尾插法 /////////////////////////////
    void push_back(const T& nodeData)
    {
        single_list_node<T>* newNodePtr = new struct single_list_node<T>;
        // 指向新的节点
        end_->next = newNodePtr;
        // 移动指针
        end_ = newNodePtr;
        // 修改其data数据
        end_->data = nodeData;
        cout << "完成操作"<< endl;
    }

    /////////////////////// 查询元素 /////////////////////////////////////
    bool getElem(const int num, T& data)
    {
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num; i++)
        {
            tempPtr = tempPtr->next;
            if(tempPtr == end_ && i != num-1)
            {
                return false;
            }
        }
        data = tempPtr->data;
        return true;
    }
    ///////////////////////   增加元素  ////////////////////////////////////
    bool add(const int num, const T& data)
    {
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num; i++)
        {
            // 得到第num个元素的指针
            tempPtr = tempPtr->next;
            if(tempPtr == end_ && i != num - 1)
            {
                return false;
            }
        }
        // 开始插入
        // 首先将第num个元素的next指向新的元素的地址
        // 新元素的next指向第num个元素的next

        // 申请空间
        struct single_list_node<T>* newNode = new struct single_list_node<T>;
        newNode->data = data;
        struct single_list_node<T>* tempNext = tempPtr->next;
        tempPtr->next = newNode;
        newNode->next = tempNext;
        return true;
    }
    /////////////////////// 删除元素 ///////////////////////////////////
    bool deleteElem(const int num)
    {
        // 删除最后一个元素
        // 时间复杂度为O(num)
        int size = getSize();
        if(size < num || num <= 0)
        {
            return false;
        }
        // num一定位于 size >= num >0
        // 删除第一个元素
        if(size == 1)
        {
            head_->next = nullptr;
            end_ = head_;         
            return true;
        }
        struct single_list_node<T>* tempPtr = head_;
        // 指向第num-1元素地址
        for(int i = 0; i < num-1; i++)
        {
            tempPtr = tempPtr->next;
        }
        if(num == size)
        {
            // 这里要修改end_
            tempPtr->next = nullptr;
            end_ = tempPtr;
            return true;
        }
        // 现在tempPtr位于第num - 1个元素
        // 首先将num-1的next定位到num + 1就ok了
        tempPtr->next = tempPtr->next->next;
        return true;
    }

    /////////////////////// 获得头尾元素 ///////////////////////////////////
    struct single_list_node<T>* getHead() const
    {
        return this->head_;
    }

    struct single_list_node<T>* getEnd() const
    {
        return this->end_;
    }
    //////////////////////// 判断元素是否为空 ///////////////////////////////
    bool isEmpty()
    {
        return (head_ == end_);
    }
    //////////////////////// 获得元素个数 ///////////////////////////////
    int getSize()
    {
        struct single_list_node<T>* tempPtr = head_;
        int count = 0;
        // 思想就是移动指针
        while(tempPtr != end_)
        {
            tempPtr = tempPtr->next;
            count += 1;
        }
        return count;
    }
    //////////////////////// 打印元素(int\string\char使用) ///////////////////////////////
    void printInt()
    {
        struct single_list_node<int>* tempPtr = head_;
        while (tempPtr != end_)
        {
            tempPtr = tempPtr->next;
            cout << tempPtr->data << endl;
        }
        cout << end_->data << endl;
    }

    //////////////////////// 释放内存 ///////////////////////////////
    ~List()
    {
        struct single_list_node<T>* tempPtr;
        while(head_ != end_)
        {
            tempPtr = head_->next;
            delete head_;
            head_ = tempPtr;
        }
        delete end_;
        cout << "释放完成" << endl;
    }
};


int main(int argc, char *argv[])
{
    // struct single_list_node<int> n1;
    // n1.data = 10;
    List<int> list;
    int data;
    bool flag;
    cout << "/////////////////测试push_bcak()和获得元素/////////////////"<< endl;
    cout << "list head = " << list.getHead() << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    cout << "list head = " << list.getHead() << endl;
    flag = list.getElem(1,data);
    cout << "list[1] = " <<  (flag? data : -1) << endl;
    flag = list.getElem(2,data);
    cout << "list[2] = " <<  (flag? data : -1) << endl;
    flag = list.getElem(3,data);
    cout << "list[3] = " <<  (flag? data : -1) << endl;
    cout << "当前元素个数" << list.getSize() << endl;

    cout << "/////////////////测试增加/////////////////" << endl;
    flag = list.add(1,data);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    if (flag)
    {
        cout << "list[4] = " << data << endl;    
    }
    flag = list.add(4,data);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    if (flag)
    {
        cout << "list[5] = " << data << endl;    
    }
    cout << "如果在第6个元素后面操作" << endl;
    flag = list.add(6,data);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    if (flag)
    {
        cout << "list[5] = " << data << endl;    
    }
    cout << "/////////////////测试删除/////////////////" << endl;
    cout << "删除第一个元素" << endl;
    flag = list.deleteElem(1);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    list.printInt();
    
    cout << "删除最后一个元素" << endl;
    flag = list.deleteElem(list.getSize());
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    list.printInt();

    cout << "删除不存在的元素" << endl;
    flag = list.deleteElem(list.getSize()+1);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    list.printInt();

    cout << "删除存在问题" << endl;

    cout << "/////////////////测试修改/////////////////" << endl;
    

    return 0;
}

