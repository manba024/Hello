//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//using namespace std;
//void Back(char * pIp, short idx);
//char * defangIPaddr(char * address);
//int main()
//{
//	char ip[30];
//	while (scanf("%s",ip)!=EOF)
//	{
//		if (strlen(ip) > 15)
//			break;
//		defangIPaddr(ip);
//		printf("%s\n", ip);
//	}
//	getchar();
//	return 0;
//}
//
//void Back(char * pIp, short idx)
//{
//	for (short i = strlen(pIp); i > idx; i--)
//		pIp[i + 2] = pIp[i];
//	pIp[idx + 1] = pIp[idx];
//	pIp[idx] = '[';
//	pIp[idx + 2] = ']';
//}
//
//
//char * defangIPaddr(char * address) {
//	short i = 0;
//	while (address[i] != '\0')
//	{
//		if (address[i] == '.')
//		{
//			//Back(address, i);
//			for (short j = strlen(address); j > i; j--)
//				address[j + 2] = address[j];
//			address[i + 1] = address[i];
//			address[i] = '[';
//			address[i + 2] = ']';
//			i += 2;
//		}
//		else
//			i++;
//	}
//	return address;
//}

//c++ 
/*
	string::size_type;
	find(),insert(),string::npos
*/
/*
#include <iostream>
#include <string>
using namespace std;
string defangIPaddr(string address);
int main()
{
	string addres;
	cin >> addres;
	addres = defangIPaddr(addres);
	getchar();
	return 0;
}

string defangIPaddr(string address)
{
	string::size_type idx = 0;
	for (short i = 0; i < 3; i++)
	{
		idx = address.find(".",idx);
		if (idx != string::npos)
		{
			address.insert(idx + 1, "]");
			address.insert(idx, "[");
			idx += 2;
		}
	}
	return address;
} 

*/

/*
	C++ 获取本地时间
*/

#include <time.h>
#include <stdio.h>
#define TIME24 86400
int main()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%X",localtime(&t));
	
	struct tm *local = localtime(&t);
	printf("hour: %2d\n", local->tm_hour);
	printf("min: %2d\n", local->tm_min);
	printf("sec: %2d\n", local->tm_sec);
	unsigned char hour, min, sec;
	hour = local->tm_hour;
	min = local->tm_min;
	sec = local->tm_sec;
	int nums = hour * 60 * 60 + min * 60 + sec;		
	if (nums < TIME24)
		nums = TIME24 - nums;
	printf("%d\n",nums);
	puts(tmp); 
	getchar();
	return 0;
}
