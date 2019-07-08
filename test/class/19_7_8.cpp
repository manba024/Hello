
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

//class CTCPClientSocket
//{
//	
//};
namespace a {
	int count = 0;
}
int count = 0;

void doSomeWork() {
	std::cout << "dosomework函数正在另一个线程上运行。" << std::endl;
	int data = ::count++;
	// Pause for a moment to provide a delay to make
	// threads more apparent.
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "工作线程调用的函数已结束。" << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i) {

		threads.push_back(std::thread(doSomeWork));
		std::cout << "main（）线程在启动新线程后调用此函数" << std::endl;
	}

	for (auto& thread : threads) {
		thread.join();
	}

	getchar();
	return 0;
}