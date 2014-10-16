/*************************************************************************
    > File Name: 2-string.cpp
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年08月07日 星期四 10时39分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
class String
{
public:
String(const char *str=NULL);
String(const String &another);
~String();
String & operater =(const String &rhs);
private:
char *m_data;
}
//==================================================================
String::String(const char *str)
{
if(str==NULL)
{
m_data=new char[1];
m_data[0]='\0';
}
else
{
m_data=new char[strlen(str)+1];
strcpy(m_data,str);
}
}
//============================================================
