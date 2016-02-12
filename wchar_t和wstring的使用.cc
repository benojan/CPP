#include <iostream>
#include <locale>
using namespace std;
 
int main()
{
	setlocale(LC_ALL,"zh_CN.UTF-8"); //便约要
	wstring ws = L"快活险";
	wcout << ws[0] << endl;
	wcout << ws << endl;
	wcout << ws.length() << endl;
	
	wchar_t wc[4] = L"尔好兮";
	wcout << wc[0] << endl;
	wcout << wc << endl;
	wcout << wcslen(wc) << endl;
	//C函数：
	wprintf(L"%lc\n", wc[0] );
	wprintf(L"%d\n", wcslen(wc) );
	wprintf(L"%ls\n", wc );
}
