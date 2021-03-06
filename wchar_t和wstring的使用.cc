//===============================================
//Linux Mint平台
//g++版本4.8.4可用，查看g++版本命令：g++ --version

#include <iostream>
//#include <locale> //无需包含?
using namespace std;
 
//locale::classic() //获取经典的C的locale，相当于local("C");
//locale loc(""); //从环境变量LANG中读取默认的locale对象
//locale::global(loc) //安装全局locale对象，相当于C语言的locale调用了std::setlocale(LC_ALL,"XXX");

int main()
{
	locale loc(""); //linux下配置utf-8
	//locale loc("zh_CN.UTF-8"); //作用同上一行
	locale::global(loc);
	
	//setlocale(LC_ALL,"zh_CN.UTF-8"); //c语言配置方式
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
//win10下，使用VS2015

#include <iostream>
#include <locale>
#include <clocale>
using namespace std;

int main()
{
	locale loc(""); //windows下设置区域为默认的locale，即chs
	//locale loc("chs") //上一行或此行
	
	wcout.imbue(loc);
	//locale::global(loc); //若上一行换成此行：重定向到文件能输出，命令行下只显示c语言的部分。
	                       //重定向的方法：命令行下程序名后加【>> a.txt】
	
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
	setlocale(LC_ALL,""); //配置后让wprintf正常工作，即c语言的配置方式
	//setlocale(LC_ALL,"chs"); //上一行或此行
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
//---------------
//可以输出到文件，为utf-8格式

#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

int main()
{
	wstring ws = L"快活险"; //\x5FEB\x6D3B\x9669
	wofstream out(L"你好.txt");
	
	locale loc(""); //输出前同样要设置
	out.imbue(loc);
	
	out << ws << endl;
	out.close();
	
	system("pause");
}


//===============================================
//参考资料：
http://blog.csdn.net/haiross/article/details/45074355 [C++中的locale设置（即系统区域设置）]
http://blog.csdn.net/wallaceli1981/article/details/6116738 [C++ 标准库的 locale 类用法]
https://gcc.gnu.org/onlinedocs/libstdc++/manual/localization.html [libstd c++ localization章节]

//-----------------------
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


//===============================================
locale::category 常量与 setlocale() 中的 category 参数对应关系
//-------------------

locale::category 常量         setlocale() 中的 category
//------------------------------------------------------
all                           LC_ALL
collate                       LC_COLLATE
ctype                         LC_CTYPE
messages                      LC_MESSAGES
monetary                      LC_MONETARY
none                          表示所有 category 的空集（LC_ALL 的补集）
numeric                       LC_NUMERIC
time                          LC_TIME
