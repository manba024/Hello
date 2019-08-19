#include <iostream>
#include <list>
#include <string>
using namespace std;
/********************************************************************************
* sprintf以及sprintf_s的使用
********************************************************************************/

int main()
{
    /*char State1[50] = "ABCDE";
    char State2[50] = "ABCDE";
    string strTest("asdf");
    sprintf_s(State1, sizeof(State1), "%s", strTest.c_str());
    sprintf(State2, "%s", strTest.c_str());*/
    const int a = 10;
    int * p = (int *)&a;
    *p = 100;
    cout << a << endl;
    getchar();
    return 0;
}