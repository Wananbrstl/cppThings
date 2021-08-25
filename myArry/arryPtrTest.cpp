#include <iostream>
using namespace std;
int main()
{
    int* intArry = new int[10];
    int* a = new int[20];
    for(int i = 0;i<10; i++)
    {
        intArry[i] = i;
        cout << "intArry["<<i<<"]= "<< i;
    }
    cout << endl;
    for(int i = 0;i<20; i++)
    {
        a[i] = i;
        cout << "a["<<i<<"]= "<< i;
        cout << endl;
    }

    delete a;
    delete intArry;
    for(int i = 0;i<10; i++)
    {
        intArry[i] = i;
        cout << "intArry["<<i<<"]= "<< i;
        cout << endl;
    }
    for(int i = 0;i<20; i++)
    {
        a[i] = i;
        cout << "a["<<i<<"]= "<< i;
        cout << endl;
    }
    return 0;
}

