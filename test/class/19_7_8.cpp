
#include <iostream>
#include <thread>
#include <vector>
#include "19_7_8Message.h"
using namespace std;
typedef unsigned char       BYTE;
typedef unsigned int        UINT;

///类说明
class CTCPClientSocket;

struct IClientSocketService
{
public:
	//网络读取消息
	virtual bool OnSocketReadEvent(NetMessageHead* pNetHead, void * pNetData, UINT uDataSize, CTCPClientSocket * pClientSocket) = 0;
	//网络连接消息
	virtual bool OnSocketConnectEvent(UINT uErrorCode, CTCPClientSocket * pClientSocket) = 0;
	//网络关闭消息
	virtual bool OnSocketCloseEvent() = 0;
};

class A {
public:
	A(int a) { cout << "A() " << a << endl; };
	virtual ~A() { cout << "~B()" << endl; };
};
class B : public A
{
public:
	B(int a) :A(a) { cout << "B()" << endl; };
	virtual ~B() { cout << "~B()" << endl; };
};

namespace a {
	int count = 0;
}
int count = 0;

struct Node {
	int value;
	Node* next;
};
//头
Node* HanderInit(const short len);
void printList(Node* hander);
Node* FlipList(Node* hander, const short len);
int main()
{
	Node* hander = HanderInit(10);
	printList(hander);
	cout << "-------" << endl;
	hander = FlipList(hander, 10);
	printList(hander);
	getchar();
	return 0;
}

Node* HanderInit(const short len)
{
	Node* hander = nullptr;//(Node*)malloc(sizeof(Node));
	Node* tmp = nullptr;
	for (short i = 0; i < len; i++)
	{
		if (0 == i)
		{
			hander = (Node*)malloc(sizeof(Node));
			hander->value = i;
			tmp = hander;
			continue;
		}
		tmp->next = (Node*)malloc(sizeof(Node));
		tmp->next->value = i;
		tmp = tmp->next;
		tmp->next = nullptr;
	}
	return hander;
}

void printList(Node * hander)
{
	while (hander != nullptr)
	{
		cout << "Node: " << hander->value << endl;
		hander = hander->next;
	}
}

Node* FlipList(Node * hander, const short len)
{
	Node *pCurrent, *pPre, *pNext;
	pPre = hander;
	pCurrent = hander->next;
	while (pCurrent)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}
	hander->next = nullptr;
	return pPre;
}
