#include <iostream>
using namespace std;
int numJewelsInStones(string J, string S);

typedef unsigned char BYTE;
int main()
{
	cout << numJewelsInStones("aA", "aAAbbbb");
	getchar();
	return 0;
}
int numJewelsInStones(string J, string S)
{
	BYTE count = 0;
	for (BYTE i =0;i<J.length();i++)
	{
		for (BYTE x = 0;x<S.length();x++)
		{
			x = S.find(J[i], x);
			if (x == 255)
				break;
			count++;
		}
	}
	return count;
}