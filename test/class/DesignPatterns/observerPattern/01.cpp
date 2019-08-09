#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

/********************************************************************************
* 观察者模式1.0
* 1、每拓展一个终端代码量需要成倍增长，且繁琐
* 2、存在大量的重复代码
* 3、放在复杂一些的场景可能会造成类的相互引用
********************************************************************************/

class Android {
public:
    Android() {};
    virtual ~Android() {};
    void recvMSG(string msg) { cout << "Android ---- : " << msg << endl; };
};
class Ios {
public:
    Ios() {};
    virtual ~Ios() {};
    void recvMSG(string msg) { cout << "Ios ---- : " << msg << endl; };
};
class Web {
public:
    Web() {};
    virtual ~Web() {};
    void recvMSG(string msg) { cout << "Web ---- : " << msg << endl; };
};

class CsdnBlog {
public:
    CsdnBlog() {};
    virtual ~CsdnBlog() {};
    void addMsg(string msg) {msgQueue.push(msg);}
    void Notify() {
        while (!msgQueue.empty())
        {
            auto andIt = androidList.begin();
            auto iosIt = iosList.begin();
            auto webIt = webList.begin();
            bool isAndroid = true;
            bool isIos = true;
            bool isWeb = true;
            while (isAndroid && isIos && isWeb)
            {
                if (andIt == androidList.end())
                    isAndroid = false;
                else
                {
                    (*andIt)->recvMSG(msgQueue.front());
                    ++andIt;
                }
                /**/
                if (iosIt == iosList.end())
                    isIos = false;
                else
                {
                    (*iosIt)->recvMSG(msgQueue.front());
                    ++iosIt;
                }
                /**/
                if (webIt == webList.end())
                    isIos = false;
                else
                {
                    (*webIt)->recvMSG(msgQueue.front());
                    ++webIt;
                }
            }
            msgQueue.pop();
        }
    };
    void addAndroid(Android* android) { androidList.push_back(android); };
    void addIos(Ios* ios) { iosList.push_back(ios); };
    void addWeb(Web* web) { webList.push_back(web); };
private:
    list<Android*> androidList;
    list<Ios*> iosList;
    list<Web*> webList;
    queue<string> msgQueue;

};


int main()
{
    CsdnBlog csdnBlog;
    Android *android = new Android();
    Ios *ios = new Ios();
    Web *web = new Web();
    csdnBlog.addAndroid(android);
    csdnBlog.addIos(ios);
    csdnBlog.addWeb(web);
    csdnBlog.addMsg("asdf");
    csdnBlog.Notify();
    delete android;
    delete ios;
    delete web;
    android = nullptr;
    ios = nullptr;
    web = nullptr;
    getchar();
    return 0;
}