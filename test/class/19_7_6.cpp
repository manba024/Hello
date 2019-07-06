/*
	�̳С���̬������ָ������������������ຯ��û���黯����Ĭ��ִ�и��ຯ��
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
	virtual bool CanBeginGame() { return true; };					//�Ƿ���Կ�ʼ��Ϸ
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