#include <iostream>
using namespace std;

typedef unsigned char BYTE;
struct BatchBet
{
	BYTE	DeskStation;				//��ע���λ��
	int		BetCount;					//��ע������
};

struct BatchBetResult
{
	__int64		i64AreaMaxZhu[6];		//ÿ���������¶���ע
	BatchBet 	betinfo;
	void*		pBet;
};

struct	C_S_UserNote
{
	BYTE	byDeskStation;
	int		iChouMaType;		//��������
	int		iNoteArea;			//��ע����
	C_S_UserNote()
	{
		byDeskStation = -1;
		iChouMaType = -1;
		iNoteArea = -1;

	}
};
int main()
{
	int m_i64AreasMaxZhu[5];
	BatchBet betinfo;
	betinfo.DeskStation = 1;
	betinfo.BetCount = 1;
	char* pSendData = new char[sizeof(BatchBetResult) - 4 ];
	memcpy(pSendData, m_i64AreasMaxZhu, sizeof(m_i64AreasMaxZhu));
	memcpy(pSendData + sizeof(m_i64AreasMaxZhu), &betinfo, sizeof(betinfo));
	memset(&betinfo, 0, sizeof(betinfo));
	memcpy(&betinfo, pSendData+ sizeof(m_i64AreasMaxZhu), sizeof(BatchBet));
	betinfo;
	getchar();
	return 0;
}