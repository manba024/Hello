#include <iostream>
#include <list>
#include <string>
using namespace std;
/********************************************************************************
* ����ת��
* static_cast<����˵����>(���ʽ)
* dynamic_cast<����˵����>(���ʽ)
* const_cast<����˵����>(���ʽ)
* reinterpret_cast<����˵����>(���ʽ)
********************************************************************************/


class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};
//����
class Blog
{
public:
    Blog() {}
    virtual ~Blog() {}
    void Attach(Observer *observer) { m_observers.push_back(observer); }	 //��ӹ۲���
    void Remove(Observer *observer) { m_observers.remove(observer); }        //�Ƴ��۲���
    void Notify() //֪ͨ�۲���
    {
        list<Observer*>::iterator iter = m_observers.begin();
        for (; iter != m_observers.end(); iter++)
            (*iter)->Update();
    }
    virtual void SetStatus(string s) { m_status = s; } //����״̬
    virtual string GetStatus() { return m_status; }    //���״̬
private:
    list<Observer* > m_observers; //�۲�������
protected:
    string m_status; //״̬
};


//���岩����
//csdn
class BlogCSDN : public Blog
{
private:
    string m_name; //��������
public:
    BlogCSDN(string name) : m_name(name) {}
    ~BlogCSDN() {}
    void SetStatus(string s) { m_status = "CSDN֪ͨ : " + m_name + s; } //��������״̬��Ϣ
    string GetStatus() { return m_status; }
};

//����۲���
class ObserverBlog : public Observer
{
private:
    string m_name;  //�۲�������
    Blog *m_blog;   //�۲�Ĳ��ͣ���Ȼ��������ʽ���ã��Ϳ��Թ۲�������
public:
    ObserverBlog(string name, Blog *blog) : m_name(name), m_blog(blog) {}
    ~ObserverBlog() {}
    void Update()  //��ø���״̬
    {
        string status = m_blog->GetStatus();
        cout << m_name << "-------" << status << endl;
    }
};

int main()
{
    //int num = 0x00636261;//��16���Ʊ�ʾ32λint��0x61���ַ�'a'��ASCII��
    //int * pnum = &num;  
    //char * pstr = reinterpret_cast<char *>(pnum);
    //cout << "pnumָ���ֵ: " << pnum << endl;
    ////ֱ�����pstr�������ָ����ַ��������������ת����Ϊ�˱�֤���pstr��ֵ
    //cout << "pstrָ���ֵ: " << static_cast<void *>(pstr) << endl;
    //cout << "pnumָ�������: " << hex << *pnum << endl;
    //cout << "pstrָ�������: " << pstr << endl;
    //pstr = "adf";
    //cout << "pnumָ�������: " << hex << *pnum << endl;
    //cout << "pstrָ�������: " << pstr << endl;

    ////static_cast
    //int m = 100;
    //long n = static_cast<long>(m);
    //char ch = static_cast<char>(m);
    //int *p1 = static_cast<int*>(malloc(10 * sizeof(int)));
    //void *p2 = static_cast<void*>(p1);

    Blog *blog = new BlogCSDN("asdf");
    Observer *observer1 = new ObserverBlog("asdf", blog);
    blog->Attach(observer1);
    blog->SetStatus("�������ģʽC++ʵ�֣�15�������۲���ģʽ");
    blog->Notify();
    delete blog;
    delete observer1;
    getchar();
    return 0;
}