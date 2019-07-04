

#include <windows.h>  
#include <iostream>  
#include <process.h>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;

struct MyStruct
{
	int a;
	int b;
	MyStruct()
	{
		memset(this, 0, sizeof(MyStruct));
	}
};
#define CARD_MAX_COUNT      54
#define CARD_NORMAL_COUNT   52

void YatesShuffle(unsigned char *pCard, int nCardCount)
{
	srand((unsigned int)(time((0))));
	int k, nIndex;
	unsigned char temp;
	for (k = nCardCount - 1; k > 0; k--)
	{
		nIndex = rand() % (k + 1);
		temp = pCard[nIndex];
		pCard[nIndex] = pCard[k];
		pCard[k] = temp;
	}
}
void ShuffleCard(unsigned char *pCardList, int nShuffleCount)
{
	int k;
	char pszCards[CARD_MAX_COUNT] = {
		0x01, 0x02 ,0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D,		//方块 2 - A
		0x11, 0x12 ,0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,		//梅花 2 - A
		0x21, 0x22 ,0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,		//红桃 2 - A
		0x31, 0x32 ,0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D,		//黑桃 2 - A
		0x4E, 0x4F };
	int a[CARD_MAX_COUNT] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,
							 1,1,1,1,1,1,1,1,1,1,1,1,1,
							 1,1,1,1,1,1,1,1,1,1,1,1,1,
							 1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	int debug = sizeof(a);
	for (k = 0; k < nShuffleCount; k++)
		memcpy(pCardList + k * CARD_NORMAL_COUNT, pszCards, CARD_NORMAL_COUNT);
	YatesShuffle(pCardList, nShuffleCount*CARD_NORMAL_COUNT);
}
void printCards(unsigned char *pCardList, int nCardCount)
{
	for (int i = 0; i < nCardCount; i++)
		cout << pCardList[i] << " " << endl;
}
int main()
{
	//BYTE						m_UserCardTotal[54];	//总的牌
	//ShuffleCard(m_UserCardTotal, 1);					//一幅牌 
	//printCards(m_UserCardTotal, CARD_NORMAL_COUNT);
	//BYTE pszCards[CARD_MAX_COUNT] = {
	//	0x01, 0x02 ,0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D,		//方块 2 - A
	//	0x11, 0x12 ,0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,		//梅花 2 - A
	//	0x21, 0x22 ,0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,		//红桃 2 - A
	//	0x31, 0x32 ,0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D,		//黑桃 2 - A
	//	0x4E, 0x4F };
	//for (int i = 0; i < CARD_MAX_COUNT; i++)
	//{
	//	//cout << pszCards[i] << endl;
	//	cout << hex << int(pszCards[i]&0x0F) << endl;
	//	//cout << pszCards[i]<< endl;
	//}
		
		/*if (pszCards[i] & 0x0F == 0x0A)
		{
		}*/
		//cout << pszCards[i] & 0x0F << endl;
	cout << hex << int(0x4E & 0x0f) << endl;
	cout << hex << int(0x4F & 0x0f) << endl;
	return 0;
}




