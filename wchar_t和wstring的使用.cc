#include <iostream>
#include <locale>
using namespace std;
 
int main()
{
	locale loc("zh_CN.UTF-8"); //linux下配置utf-8，默认是c。//g++版本4.8.4可用， 查看g++版本命令： g++ --version
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

//参考资料：
-http://blog.csdn.net/haiross/article/details/45074355
-http://blog.csdn.net/wallaceli1981/article/details/6116738

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
lt_LN.bit7  ISO Latin, 7 bit
lt_LN.bit8  ISO Latin, 8 bit
POSIX       POSIX conventions (English, 7 bit)
但它们尚未标准化。

locale::classic() //获取经典的C的locale，相当于local("C");
locale loc(""); //从环境变量LANG中读取默认的locale对象
locale::global(loc) //安装全局locale对象，相当于C语言的locale调用了std::setlocale(LC_ALL,"XXX");
