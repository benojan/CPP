/**
* 功能：将unicode以gkb编码显示到命令行。
*/

// ===============================================
// Linux Mint平台
// g++版本4.8.4可用，查看g++版本命令：g++ --version

#include <iostream>
//#include <locale> //无需包含?
using namespace std;
 
//locale::classic() //获取经典的C的locale，相当于local("C");
//locale loc(""); //从环境变量LANG中读取默认的locale对象
//locale::global(loc) //安装全局locale对象，相当于C语言的locale调用了std::setlocale(LC_ALL,"XXX");

int main()
{
	// 方式一：c++
	locale loc(""); //linux下配置utf-8
	//locale loc("zh_CN.UTF-8"); //作用同上一行
	locale::global(loc);
	
	// 方式二：c
	//setlocale(LC_ALL,"zh_CN.UTF-8");
	
	// 最好用unicode编码个十六进制表示汉字！
	string s = "讲弗着";
	wcout << s.c_str() << endl; //string这样输出！
	
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wcout << ws[0] << endl;
	wcout << ws << endl;
	wcout << ws.length() << endl;
	
	wchar_t wc[4] = L"尔好兮"; //\x5C14\x597D\x516E
	wcout << wc[0] << endl;
	wcout << wc << endl;
	wcout << wcslen(wc) << endl;
	
	wprintf(L"%lc\n", wc[0] );
	wprintf(L"%ls\n", wc );
	wprintf(L"%d\n", wcslen(wc) );
	
	//十六进制输出：
	char ch1 = 'A';
	wchar_t ch2 = L'尔'; //\x5C14
	wcout << (int) ch1 << endl; //十进制输出
	wcout << hex << (int) ch1 << L' ' << (int) ch2 << endl; //十六进制输出
}

//===============================================
//Windows平台下部分编译器支持

//---------------
//win10下，使用VS2019

#include <iostream>
using namespace std;

int main()
{
	// 方式：c
	setlocale(LC_ALL, ""); //配置后让wprintf正常工作，即c语言的配置方式
	//setlocale(LC_ALL,"chs"); //上一行或此行

	// 最好用unicode编码个十六进制表示汉字！
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wcout << ws[0] << endl;
	wcout << ws << endl;
	wcout << ws.length() << endl;

	wchar_t wc[4] = L"尔好兮"; //\x5C14\x597D\x516E
	wcout << wc[0] << endl;
	wcout << wc << endl;
	wcout << wcslen(wc) << endl;

	//使用C语言函数wprintf：
	wprintf(L"%c\n", wc[0]);
	wprintf(L"%ls\n", wc);
	wprintf(L"%d\n", wcslen(wc));

	//十六进制输出：
	char ch1 = 'A';
	wchar_t ch2 = L'尔'; //\x5C14
	wcout << (int)ch1 << endl; //十进制输出
	wcout << hex << (int)ch1 << L' ' << (int)ch2 << endl; //十六进制输出

	system("pause");
}
