#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

typedef pair<string, int> PAIR;

ostream& operator<<(ostream& out, const PAIR& p) {
	return out << p.first << "\t" << p.second;
}


struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};

inline bool CmpByvalue(const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second < rhs.second;
}

int main() {
	map<int, int> name_score_map;
	//name_score_map["LiMin"] = 90;
	//name_score_map["ZiLinMi"] = 79;
	//name_score_map["BoB"] = 92;
	//name_score_map.insert(make_pair("Bing", 99));
	//name_score_map.insert(make_pair("Albert", 86));
	////把map中元素转存到vector中 
	//vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
	//sort(name_score_vec.begin(), name_score_vec.end(), CmpByvalue);
	//// sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
	//for (int i = 0; i != name_score_vec.size(); ++i) {
	//	cout << name_score_vec[i] << endl;
	//}
	//auto it = name_score_map.begin();
	//for (; it != name_score_map.end();it++)
	//{
	//	(*it).second;
	//}
	name_score_map[9] = 1;
	name_score_map[8] = 2;
	name_score_map[7] = 3;
	auto it = name_score_map.end();
	it--;
	for (; it != name_score_map.begin(); it--)
	{
		//cout << (*it).first << endl;
		//cout << (*it).first << " " << (*it).second << endl;
	}
	
	//cout << (*it).first << endl;
	//cout << (*it).second << endl;
	//int arr1[10] = { 0 };
	//int arr2[2][10] = { 0 };
	//arr2[0][0] = 1;
	//arr2[1][0] = 2;
	//memcpy(arr1, arr2[1], sizeof(arr2[1]));
	//cout << arr1[0] << endl;
	////for (; it != name_score_map.end(); it++)
	////{
	////	cout<<
	////}
	//char string1[50];
	//char string2[2][50];
	//int file_number = 0;

	//sprintf(string2[0], "file.%d", 1);
	//sprintf(string2[1], "file.%d", 2);
	//cout << string2[0] << endl;
	//cout << string2[1] << endl;
	//
	//char test[61];
	//char from[3][61];
	//sprintf(test, "nick");
	//sprintf_s(from[0], 61, test);

	multimap<int, int> dict;
	dict.insert(make_pair(1, 1));
	dict.insert(make_pair(13, 2));
	dict.insert(make_pair(1, 3));
	
	cout << dict.size() << endl;
	auto mit = dict.end();
	mit--;
	for (int i =0;i<dict.size();i++)
	{
		cout << mit->first << " " << mit->second << endl;
		mit--;
	}
	//for (; mit != dict.begin(); mit--)
		
	getchar();
	return 0;
}