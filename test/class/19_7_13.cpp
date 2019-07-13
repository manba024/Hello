#include <iostream>
#include <string>
using namespace std;

template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}
struct IModuleManageServer {
public:
	///初始化函数 
	virtual bool InitService() = 0;
	///取消初始化函数 
	virtual bool UnInitService() = 0;
	///初始化函数 
	virtual bool StartService(int &errCode) = 0;
	///初始化函数 
	virtual bool StoptService() = 0;
	///删除函数
	virtual bool DeleteService() = 0;
};
//template<class GameDeskClass, int uBasePoint, int uLessPointTimes>
//class CGameModuleTemplate : public IModuleManageServer
//{
//public:
//	void show1(const T1 &a) { cout << "show1:" << a << endl; }
//	void show2(const T2 &a) { cout << "show2:" << a << endl; }
//};
typedef int(*fp_t)(char c);

int f0(char c) { printf("f0,c=%c\n", c); return 0; }
int f1(char c) { printf("f1,c=%c\n", c); return 1; }
struct student
{
	char mark;
	long num;
	float score;
};
union test
{
	char mark;
	long num;
	float score;
};
int main()
{
	//show<int,1> a;
	//a.show1(1);
	//a.show2("s");
	//int ret;
	//fp_t fp;
	//fp = f0;
	//ret = fp('a');
	cout << sizeof(student) << endl;
	cout << sizeof(test) << endl;
	student s;
	memset(&s, 0, sizeof(student));
	char *s1 = &s.mark;
	long *s2 = &s.num;
	float *s3 = &s.score;
	test t;
	memset(&t, 0, sizeof(test));
	char *t1 = &t.mark;
	long *t2 = &t.num;
	float *t3 = &t.score;
	t.mark = sizeof(double);
	getchar();
	return 0;
}