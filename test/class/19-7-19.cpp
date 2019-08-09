#include <iostream>
#include "../tinyxml/tinystr.h"
#include "../tinyxml/tinyxml.h"
using namespace std;
//dom 节点

struct S1 {
    int a;
    int b;
    S1()
    {
        memset(this, 0, sizeof(S1));
    };
};
void FuncTest(int a, int b = 1)
{
    cout << a << endl;
}
int main()
{
    //TiXmlDocument xml_doc;
    //if (!xml_doc.LoadFile("File name"), TIXML_ENCODING_UTF8) //加载文件名字
    //{
    //    return false;
    //}
    //const TiXmlElement* xml_element = xml_doc.FirstChildElement("Config");  //加载节点
    //if (nullptr == xml_element)
    //{
    //    return false;
    //}
    FuncTest(1);
    getchar();
    return 0;
}