#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <windows.h> 
using namespace std;
string WORD2string(WORD w)
{
char tmpbuff[16];
sprintf(tmpbuff,"%d",w);
string res=tmpbuff;
return res;
}
int main()
{
	
	SYSTEMTIME now;
	GetLocalTime(&now);
	string op1="copy C:\\Users\\Administrator\\Desktop\\作业\\template.docx C:\\Users\\Administrator\\Desktop\\作业\\";
	string path="C:\\Users\\Administrator\\Desktop\\作业\\";
	string docx=".docx";
	string copy,log;
	string fmtmon=WORD2string(now.wMonth);
	string fmtday=WORD2string(now.wDay);
	if(fmtmon.length()<2)
	{
		fmtmon="0"+fmtmon;
	 } 
	if(fmtday.length()<2)
	{
		fmtday="0"+fmtday;
	 } 
	string current=fmtmon+fmtday;
	
	cout<<"Hello World!\ndebug info:current is "<<current<<endl;
	copy=op1+current+"\\"+current+".docx"; 
	string create="md "+current;
	string enter="cd C:\\Users\\Administrator\\Desktop\\作业\\"+current;
	string open="start "+path+current+"\\"+current+docx;
	string lnk="link.vbs /target:C:\\Users\\Administrator\\Desktop\\作业\\"+current+"\\"+current+".docx /shortcut:"+"C:\\Users\\Administrator\\Desktop\\"+"今日作业.lnk";
	string found="start "+path+current;
	ifstream fin;
	ofstream fout;
	fin.open("log.txt");
	fin>>log;
	if(log!=current)
	{
	fout.open("log.txt",ios::out);
	fout<<current;
	system(enter.c_str());
	system(create.c_str());
	system(copy.c_str());
	system(open.c_str());
	//system(lnk.c_str());
	}
else
{
	system(enter.c_str());
	system(open.c_str());
	system(found.c_str());
}
}
