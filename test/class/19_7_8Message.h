#ifndef __MESSAGE__H_
#define __MESSAGE__H_

typedef unsigned long DWORD;
///�������ݰ��ṹͷ
struct NetMessageHead
{
	DWORD						uMessageSize;						///���ݰ���С
	DWORD						bMainID;							///����������
	DWORD						bAssistantID;						///������������
	DWORD						bHandleCode;						///���ݰ��������
	DWORD						bReserve;							///�����ֶ�
};
#endif
