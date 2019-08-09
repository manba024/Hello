#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

/********************************************************************************
* 观察者1.0
* 1、每拓展一个终端代码量需要成倍增长，且繁琐
* 2、存在大量的重复代码
* 3、放在复杂一些的场景可能会造成类的相互引用
*
* 观察者2.0
* 1、抽象出观察者类和主题类
* 
* 下一版本计划 
* 添加GitHub和小哈的iPhone（或者模拟多个app多个平台）
********************************************************************************/


/*
    公共函数(observer)
    1、Notify()
    2、添加观察者
    3、删除观察者
    4、发布博客
    5、删除博客
    (subject)
    1、Update()更新状态
*/

/*观察者*/
class observer {
public:
    observer() {};
    virtual ~observer() {};
    virtual void Update() {};
};
/*主题*/
class subject {
public:
    subject() {
        m_station = "";
    };
    virtual ~subject() {};
public:

    void AddObserver(observer* ob) { obList.push_back(ob); };
    void RemoveObserver(observer* ob) { obList.remove(ob); }
    void Notify() {
        auto obIteraotr = obList.begin();
        for (; obIteraotr != obList.end(); ++obIteraotr)
            (*obIteraotr)->Update();
    }
    virtual void setStation(string msg) { m_station = msg; };
    string getStation() { return m_station; };
private:
    list<observer*> obList;
protected:
    string m_station;
};

/*具体主题*/
//csdn
class csdnBlog : public subject
{
public:
    csdnBlog(string name) :m_name(name) {};
    ~csdnBlog() {};
    void setStation(string msg) { m_station = msg+"\n\tCSND:from "+m_name; }
    //string getStation() { return m_station; }
private:
    string m_name;
};
/*具体观察者*/
//小明的Android
class xiaoMing : public observer {
public:
    xiaoMing() {};
    ~xiaoMing() {};
public:
    void Update() {
        cout << csdnblog->getStation() << endl;
    };
public:
    subject* csdnblog;
};


int main()
{
    csdnBlog* cBlog = new csdnBlog("dj");
    xiaoMing* xMing = new xiaoMing();
    cBlog->AddObserver(xMing);
    xMing->csdnblog = cBlog;
    cBlog->setStation("hello,observer Mode!");
    cBlog->Notify();
    delete cBlog;
    cBlog = nullptr;
    delete xMing;
    xMing = nullptr;
    getchar();
    return 0;
}