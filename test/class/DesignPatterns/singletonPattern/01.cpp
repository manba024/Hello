/********************************************************************************
*   ����ģʽ
*   1������ģʽ(�̰߳�ȫ)
*   2������ģʽ(��Ҫ����)
********************************************************************************/

#include <iostream>
using namespace std;

class Tool
{
public:
    ~Tool() {};
    static Tool* getInstance() {
        if (nullptr == instance)
        {
            instance = new Tool();
        }
        return instance;
    };
    int add(const int& a, const int& b) {
        return a + b;
    };
private:
    Tool() {};
    static Tool *instance;
};

Tool* Tool::instance = nullptr;

class hungry
{
public:
    ~hungry() {};
    static hungry* getInstance() { return instance; };
    int add(const int& a, const int& b) {
        return a + b;
    };
private:
    static hungry* instance;       
};
hungry* hungry::instance = new hungry();

int main()
{
    auto tool = Tool::getInstance();
    cout << tool->add(1, 2) << endl;
    auto hTool = hungry::getInstance();
    cout << hTool->add(1, 2) << endl;
    getchar();
    return 0;
}



























