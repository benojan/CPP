#include <iostream>
#include <locale>
using namespace std;
 
int main()
{
	locale loc("zh_CN.UTF-8"); //linux下配置utf-8
	locale::global(loc);
	//setlocale(LC_ALL,"zh_CN.UTF-8"); //c语言配置方式
	// 最好用unicode编码个十六进制表示汉字！
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wcout << ws[0] << endl;
	wcout << ws << endl;
	wcout << ws.length() << endl;
	
	wchar_t wc[4] = L"尔好兮"; //\x5C14\x597D\x516E
	wcout << wc[0] << endl;
	wcout << wc << endl;
	wcout << wcslen(wc) << endl;
	//C函数：
	wprintf(L"%lc\n", wc[0] );
	wprintf(L"%ls\n", wc );
	wprintf(L"%d\n", wcslen(wc) );
	//十六进制输出：
	char ch1 = 'A';
	wchar_t ch2 = L'尔'; //\x5C14
	wcout << (int) ch1 << endl; //十进制输出
	wcout << hex << (int) ch1 << L' ' << (int) ch2 << endl; //十六进制输出
}
