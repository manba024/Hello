#include <iostream>
#include <list>
#include <string>
using namespace std;
/********************************************************************************
* 类型转换
* static_cast<类型说明符>(表达式)
* dynamic_cast<类型说明符>(表达式)
* const_cast<类型说明符>(表达式)
* reinterpret_cast<类型说明符>(表达式)
********************************************************************************/


class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};
//博客
class Blog
{
public:
    Blog() {}
    virtual ~Blog() {}
    void Attach(Observer *observer) { m_observers.push_back(observer); }	 //添加观察者
    void Remove(Observer *observer) { m_observers.remove(observer); }        //移除观察者
    void Notify() //通知观察者
    {
        list<Observer*>::iterator iter = m_observers.begin();
        for (; iter != m_observers.end(); iter++)
            (*iter)->Update();
    }
    virtual void SetStatus(string s) { m_status = s; } //设置状态
    virtual string GetStatus() { return m_status; }    //获得状态
private:
    list<Observer* > m_observers; //观察者链表
protected:
    string m_status; //状态
};


//具体博客类
//csdn
class BlogCSDN : public Blog
{
private:
    string m_name; //博主名称
public:
    BlogCSDN(string name) : m_name(name) {}
    ~BlogCSDN() {}
    void SetStatus(string s) { m_status = "CSDN通知 : " + m_name + s; } //具体设置状态信息
    string GetStatus() { return m_status; }
};

//具体观察者
class ObserverBlog : public Observer
{
private:
    string m_name;  //观察者名称
    Blog *m_blog;   //观察的博客，当然以链表形式更好，就可以观察多个博客
public:
    ObserverBlog(string name, Blog *blog) : m_name(name), m_blog(blog) {}
    ~ObserverBlog() {}
    void Update()  //获得更新状态
    {
        string status = m_blog->GetStatus();
        cout << m_name << "-------" << status << endl;
    }
};

int main()
{
    //int num = 0x00636261;//用16进制表示32位int，0x61是字符'a'的ASCII码
    //int * pnum = &num;  
    //char * pstr = reinterpret_cast<char *>(pnum);
    //cout << "pnum指针的值: " << pnum << endl;
    ////直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值
    //cout << "pstr指针的值: " << static_cast<void *>(pstr) << endl;
    //cout << "pnum指向的内容: " << hex << *pnum << endl;
    //cout << "pstr指向的内容: " << pstr << endl;
    //pstr = "adf";
    //cout << "pnum指向的内容: " << hex << *pnum << endl;
    //cout << "pstr指向的内容: " << pstr << endl;

    ////static_cast
    //int m = 100;
    //long n = static_cast<long>(m);
    //char ch = static_cast<char>(m);
    //int *p1 = static_cast<int*>(malloc(10 * sizeof(int)));
    //void *p2 = static_cast<void*>(p1);

    Blog *blog = new BlogCSDN("asdf");
    Observer *observer1 = new ObserverBlog("asdf", blog);
    blog->Attach(observer1);
    blog->SetStatus("发表设计模式C++实现（15）——观察者模式");
    blog->Notify();
    delete blog;
    delete observer1;
    getchar();
    return 0;
}