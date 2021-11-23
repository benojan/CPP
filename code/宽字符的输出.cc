//=================================================

/**
* 功能：输出wstring到命令行。
*/

#include <fstream>
using namespace std;

int main()
{
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wofstream out("output.txt");
	out.imbue(locale(""));
	out << ws << endl;
}

//=================================================

/**
* 功能：输出wstring到utf8文本文件。
*/

#include <fstream>
using namespace std;

int main()
{
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wofstream out("output.txt");
	out.imbue(locale("zh_CN.utf8"));
	out << ws << endl;
}
