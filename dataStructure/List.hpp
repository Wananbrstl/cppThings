#ifndef LIST_H_
#define LIST_H_

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
public:
    ////////////////////////////// 简单构造函数 /////////////////////////////
    List()
    {
        head_ = new struct single_list_node<T>;
    }

    ////////////////////////////// 拷贝构造函数 /////////////////////////////
    List(const List<T>& L)
    {
        head_ = new struct single_list_node<T>;
        struct single_list_node<T>* ptr1 = head_;
        struct single_list_node<T>* ptr2 = L.getHead();
        while(ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
            struct single_list_node<T>* tempPtr = new struct single_list_node<T>;
            ptr1->next = tempPtr;
            ptr1 = ptr1->next;
            ptr1->data = ptr2->data;
        }
        cout << "拷贝构造函数完成" << endl;
    }
    ////////////////////////////// 尾插法 /////////////////////////////
    void push_back(const T& data)
    {
        struct single_list_node<T>* newNodePtr = new struct single_list_node<T>;
        struct single_list_node<T>* ptr = head_;
        // 移动到尾部
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNodePtr;
        newNodePtr->data = data;
        newNodePtr->next = NULL;
    }

    /////////////////////// 查询元素 /////////////////////////////////////
    bool getElem(const int num, T& data)
    {
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num; i++)
        {
            tempPtr = tempPtr->next;
            if(tempPtr->next == nullptr && i != num-1)
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
        // 移动指针
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num; i++)
        {
            // 得到第num个元素的指针
            tempPtr = tempPtr->next;
            if(tempPtr->next->next == NULL && i != num - 1)
            {
                return false;
            }
        }
        // 申请空间
        struct single_list_node<T>* newNode = new struct single_list_node<T>;
        newNode->data = data;
        // 开始插入
        // 首先将第num个元素的next指向新的元素的地址
        // 新元素的next指向第num个元素的next
        struct single_list_node<T>* tempPtrNext = tempPtr->next;
        tempPtr->next = newNode;
        // 不是尾部的话
        if(tempPtrNext->next != nullptr)
        {
            // 尾部插入
            newNode->next = tempPtrNext;
        }
        return true;
    }
    /////////////////////// 删除元素 ///////////////////////////////////
    bool deleteElem(const int num)
    {
        // 移动指针
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num-1; i++)
        {
            tempPtr = tempPtr->next;
            if(tempPtr->next->next == NULL && i != num - 2)
            {
                cout << "删除 : 超出最后一个" << endl;
                return false;
            }
        }
        // 指向了第num - 1元素
        struct single_list_node<T>* tempPtrNext = tempPtr->next;
        if(tempPtr->next->next == NULL)
        {
            // 如果是最后一个元素
            tempPtr->next = NULL;
        }
        // 移动到了第num - 1个元素处
        // 直接跳过 num 处
        else
        {
            tempPtr->next = tempPtrNext->next;
        }
        // 释放空间
        delete tempPtrNext;
        return true;
    }
    /////////////////////// 修改元素 ///////////////////////////////////
    bool modifyElem(const int num, const T& data)
    {
        struct single_list_node<T>* tempPtr = head_;
        for(int i = 0; i < num; i++)
        {
            tempPtr = tempPtr->next;
            if(i != num -1 && tempPtr->next == nullptr)
            {
                return false;
            }
        }
        tempPtr->data = data;
        return true;
    }
    /////////////////////// 获得头元素 ///////////////////////////////////
    struct single_list_node<T>* getHead() const
    {
        return this->head_;
    }
    //////////////////////// 判断元素是否为空 ///////////////////////////////
    bool isEmpty()
    {
        return (!head_->next);
    }
    //////////////////////// 获得元素个数 ///////////////////////////////
    int getSize()
    {
        struct single_list_node<T>* tempPtr = head_;
        int count = 0;
        // 思想就是移动指针
        while(tempPtr->next != NULL)
        {
            tempPtr = tempPtr->next;
            count += 1;
            // cout << "+1" << endl;
        }
        return count;
    }
    //////////////////////// 打印元素(int\string\char使用) ///////////////////////////////
    void printInt()
    {
        struct single_list_node<int>* tempPtr = head_;
        for(int i = 0;tempPtr->next != nullptr; i++)
        {
            tempPtr = tempPtr->next;
            cout << i  << " : " << tempPtr->data << endl;
        }
    }

    //////////////////////// 释放内存 ///////////////////////////////
    ~List()
    {
        struct single_list_node<T>* tempPtr;
        while(tempPtr->next != nullptr)
        {
            tempPtr = head_->next;
            delete head_;
            head_ = tempPtr;
        }
        delete tempPtr;
        cout << "释放完成" << endl;
    }
};
#endif