//-------------------------------
//Linux Mint平台
//g++版本4.8.4可用，查看g++版本命令：g++ --version

#include <iostream>
#include <locale>
using namespace std;
 
//locale::classic() //获取经典的C的locale，相当于local("C");
//locale loc(""); //从环境变量LANG中读取默认的locale对象
//locale::global(loc) //安装全局locale对象，相当于C语言的locale调用了std::setlocale(LC_ALL,"XXX");

int main()
{
	locale loc("zh_CN.UTF-8"); //linux下配置utf-8，默认是c。
	locale::global(loc);
	//---------------------------
	locale loc(""); //windows下，使用VS2015。
	//locale loc("chs") //上一行或此行
	wcout.imbue(loc);
	//---------------------------
	
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
	//C函数：vs2015，设置locale后不能显示！默认可以显示！！
	wprintf(L"%lc\n", wc[0] );
	wprintf(L"%ls\n", wc );
	wprintf(L"%d\n", wcslen(wc) );
	//十六进制输出：
	char ch1 = 'A';
	wchar_t ch2 = L'尔'; //\x5C14
	wcout << (int) ch1 << endl; //十进制输出
	wcout << hex << (int) ch1 << L' ' << (int) ch2 << endl; //十六进制输出
}

//---------------------------------------
//Windows10下，使用VS2015
//可以输出到文件，为utf-8格式

#include <iostream>
#include <locale>
#include <clocale>
using namespace std;

int main()
{
	locale loc(""); //windows下设置区域为默认的locale，即chs
	//locale loc("chs") //上一行或此行
	wcout.imbue(loc);//locale::global(loc);
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
	setlocale(LC_ALL,""); //双配置，c语言的配置方式
	setlocale(LC_ALL,"chs"); //上一行或此行
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

//参考资料：
http://blog.csdn.net/haiross/article/details/45074355 [C++中的locale设置（即系统区域设置）]
http://blog.csdn.net/wallaceli1981/article/details/6116738 [C++ 标准库的 locale 类用法]
https://gcc.gnu.org/onlinedocs/libstdc++/manual/localization.html [libstd c++ localization章节]

确定一个locale,需要采用以下字符串格式：
language[_area[.code]]
下面列出了典型的语言名称：
c           Default: ANSI-C conventions (English, 7 bit)
de_DE       German in Germany
de_DE.      88591   German in Germany with ISO Latin-1 encoding
de_AT       German in Austria
de_CH       German in Switzerland
en_US       English in the United States
en_GB       English in Great Britain
en_AU       English in Australia
en_CA       English in Canada
fr_FR       French in France
fr_CH       French in Switzerland
fr_CA       French in Canada
ja_JP.jis   Japanese in Japan with Japanese Industrial Standard (JIT) encoding
ja_JP.sjis  Japanese in Japan with Shift JIS encoding
ja_JP.ujis  Japanese in Japan with UNIXized JIS encoding
ja_JP.EUC   Japanese in Japan with Extended UNIX Code encoding
ko_KR       Korean in Korea
zh_CN       Chinese in China
zh_TW       Chinese in Taiwan
//----------------
zh_CN
zh_CN.gb18030
zh_CN.gbk
zh_CN.utf8
zh_HK
zh_HK.utf8
zh_TW
zh_TW.euctw
zh_TW.utf8
//----------------
lt_LN.bit7  ISO Latin, 7 bit
lt_LN.bit8  ISO Latin, 8 bit
POSIX       POSIX conventions (English, 7 bit)
但它们尚未标准化。
