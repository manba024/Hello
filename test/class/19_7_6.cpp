/*
	继承、多态，父类指针兼容子类对象，如果父类函数没有虚化，则默认执行父类函数
*/
#include <iostream>
using namespace std;
typedef unsigned char BYTE;

class CGameDesk
{
public:
	//explicit CGameDesk(BYTE bBeginMode) {};
	CGameDesk() {};
	virtual ~CGameDesk() { cout << "~CGameDesk()" << endl; };
	virtual void test() { cout << "CGameDesk" << endl; };
	virtual bool CanBeginGame() { return true; };					//是否可以开始游戏
};
class BSManage : public CGameDesk
{
public:
	BSManage() {};
	~BSManage() { cout << "~BSManage()" << endl; };
public:
	void test() { cout << "BSManage" << endl; };
	bool CanBeginGame() { return true; };
};

class TSManage :public CGameDesk
{
public:
	TSManage() {};
	~TSManage() { cout << "~TSManage()" << endl; };
public:
	void test() { cout << "TSManage" << endl; };
	bool CanBeginGame() { return true; };
};
int main()
{
	CGameDesk* a = new BSManage();
	CGameDesk* b = new TSManage();
	a->test();
	b->test();
	delete a;
	a = nullptr;
	delete b;
	b = nullptr;
	getchar();
	return 0;
}