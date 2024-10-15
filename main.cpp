#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <shellapi.h>
using namespace std;
string WORD2string(WORD w);

int main()
{
	system("color 34");
	string name, current;
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	current = WORD2string(systime.wMonth) + WORD2string(systime.wDay);
	cout << current << endl;
	string filePath = "C:\\Users\\JingJia1\\Desktop\\homework\\";
	string saveCompareRaw = filePath + current;
	CreateDirectory(saveCompareRaw.c_str(), NULL);
	cout << saveCompareRaw << endl;
	char final[saveCompareRaw.length()] = { "cd " };
	char copy1[300] = { "copy C:\\Users\\JingJia1\\Desktop\\template.docx C:\\Users\\JingJia1\\Desktop\\homework\\" };
	char copy2[300] = { 0 };
	char copyall[300] = { 0 };
	char docname[100] = { 0 };
	string temp1 = ".docx";
	string temp2 = "\\";
	string copy1_str = copy1;
	string copy2_str = copy2;

	char path[saveCompareRaw.length()] = { 0 };
	copy2_str = current;
	for (int i = 0; i <= saveCompareRaw.length(); i++)
	{
		path[i] = saveCompareRaw[i];
	}
	for (int i = 0; i <= saveCompareRaw.length(); i++)
	{
		cout << path[i];
	}
	for (int i = 3; i <= saveCompareRaw.length() + 3; i++)
	{
		final[i] = path[i - 3];
	}
	string copyall_str = copy1_str + copy2_str + temp2 + current + temp1;
	for (int i = 0; i <= copyall_str.length(); i++)
	{
		copyall[i] = copyall_str[i];
	}
	cout << "\n" << final << "\n" << copyall << endl;
	system(final);
	system(copyall);
	string docname_str = "C:\\Users\\JingJia1\\Desktop\\homework\\";
	string docnamefinal = docname_str + current + temp2 + current + temp1;
	for (int i = 0; i <= docnamefinal.length(); i++)
	{
		docname[i] = docnamefinal[i];
	}
	cout << docname;
	ShellExecute(NULL, "open", docname, NULL, NULL, SW_SHOWMAXIMIZED);
	cout << "\a";
}
string WORD2string(WORD w)
{
	char tmpbuff[16];
	sprintf(tmpbuff, "%d", w);
	string res = tmpbuff;
	return res;
}
