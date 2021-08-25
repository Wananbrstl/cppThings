#include"List.hpp"

using namespace std;

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
    list.printInt();

    cout << "/////////////////测试增加/////////////////" << endl;
    flag = list.add(1,data);
    cout << "第一个元素前面添加" << endl;
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    if (flag)
    {
        cout << "list[4] = " << data << endl;    
    }

    
    flag = list.add(2,data);
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
    list.printInt();
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
    flag = list.deleteElem(6);
    cout << "操作 " << (flag ? "成功" : "失败") << endl;
    cout << "当前元素个数" << list.getSize() << endl;
    list.printInt();


    cout << "/////////////////测试修改/////////////////" << endl;
    cout << "修改第一个元素" << endl;
    data = 1000;
    list.modifyElem(1,data);
    list.printInt();


    cout << "修改最后一个元素" << endl;
    data = 1000;
    list.modifyElem(list.getSize(),data);
    list.printInt();

    cout << "修改中间一个元素" << endl;
    data = 1000;
    list.modifyElem(list.getSize()-1,data);
    list.printInt();


    cout << "测试拷贝构造函数" << endl;
    List<int> list2(list);
    list2.printInt();
    return 0;
}

