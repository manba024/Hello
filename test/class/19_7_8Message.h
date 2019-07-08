#ifndef __MESSAGE__H_
#define __MESSAGE__H_

typedef unsigned long DWORD;
///网络数据包结构头
struct NetMessageHead
{
	DWORD						uMessageSize;						///数据包大小
	DWORD						bMainID;							///处理主类型
	DWORD						bAssistantID;						///辅助处理类型
	DWORD						bHandleCode;						///数据包处理代码
	DWORD						bReserve;							///保留字段
};
#endif
