
#include <iostream>
#include <thread>
#include <vector>
#include "19_7_8Message.h"
using namespace std;
typedef unsigned char       BYTE;
typedef unsigned int        UINT;

///��˵��
class CTCPClientSocket;

struct IClientSocketService
{
public:
	//�����ȡ��Ϣ
	virtual bool OnSocketReadEvent(NetMessageHead* pNetHead, void * pNetData, UINT uDataSize, CTCPClientSocket * pClientSocket) = 0;
	//����������Ϣ
	virtual bool OnSocketConnectEvent(UINT uErrorCode, CTCPClientSocket * pClientSocket) = 0;
	//����ر���Ϣ
	virtual bool OnSocketCloseEvent() = 0;
};

//class CTCPClientSocket
//{
//	
//};
namespace a {
	int count = 0;
}
int count = 0;

void doSomeWork() {
	std::cout << "dosomework����������һ���߳������С�" << std::endl;
	int data = ::count++;
	// Pause for a moment to provide a delay to make
	// threads more apparent.
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "�����̵߳��õĺ����ѽ�����" << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i) {

		threads.push_back(std::thread(doSomeWork));
		std::cout << "main�����߳����������̺߳���ô˺���" << std::endl;
	}

	for (auto& thread : threads) {
		thread.join();
	}

	getchar();
	return 0;
}