#include"List.hpp"


class Person
{
    public:
        string name;
        int age;
        Person(){}
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        void showInfo() const
        {
            cout << "name = " << name << "; age = " << age << endl;
        }
};
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


    cout << "/////////////////其他类型数据结构///////////////////////" << endl;
    Person data_p;
    Person p1("Person1", 10);
    Person p2("Person2", 13);
    Person p3("Person3", 15);
    List<Person> person_list;
    person_list.push_back(p1);
    person_list.push_back(p2);
    cout << "push_back p1 p2" << endl;
    
    person_list.getElem(2,data_p);
    cout << person_list.getSize() << ": " << data_p.name << "  " << data_p.age << endl;
    cout << " size = "<< person_list.getSize() << endl;

    cout << "add(1,p1) add(3,p3)" << endl;
    person_list.add(1, p1);
    person_list.add(3, p3);

    flag = person_list.getElem(1,data_p);
    cout << "done? : " << flag << endl;
    if(flag)
    {
        cout << "1: " << "name = " << data_p.name << " age = " << data_p.age << endl;
    }

    flag = person_list.getElem(2,data_p);
    cout << "done? : " << flag << endl;
    if(flag)
    {
        cout << "2: " << "name = " << data_p.name << " age = " << data_p.age << endl;
    }
    flag = person_list.getElem(3,data_p);
    cout << "done? : " << flag << endl;
    if(flag)
    {
        cout << "3: " << "name = " << data_p.name << " age = " << data_p.age << endl;
    }
    flag = person_list.getElem(4,data_p);
    cout << "done? : " << flag << endl;
    cout << "size of " << person_list.getSize() << endl;
    if(flag)
    {
        cout << "4: " << "name = " << data_p.name << " age = " << data_p.age << endl;
    }
    cout << "//////////////////////MODIFY///////////////////////" << endl;
    Person modifyPerson("modify", 1);
    flag = person_list.modifyElem(2,modifyPerson);
    flag = person_list.getElem(2,data_p);
    cout << "done? : " << flag << endl;
    if(flag)
    {
        cout << "2: " << "name = " << data_p.name << " age = " << data_p.age << endl;
    }
    //person_list.modifyElem(2,p3);
    //cout << "name = " << data.name << " age = " << data.age << endl;
    return 0;
}

