//=================================================

/**
* 功能：输出wstring到gbk文本文件。
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
* 适用于：windows下，visual studio 2019
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

//=================================================

/**
* 功能：输出wstring文本到utf8文本文件。
* 适用于：windows下，code::blocks
*/

#include <fstream>
using namespace std;

void WriteUtf8()
{
    wstring utf8bytes = L"中国"; // unicode编码

    // 将unicode编码，转换成utf8编码
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    string utf8bytes = conv.to_bytes(unicode);

    ofstream output("output.txt");
    output << utf8bytes << endl;
}

int main()
{
    WriteUtf8();
    return 0;
}

//=================================================

/**
* 功能：打开utf8文本文件，并输出到utf8文本文件。
* 适用于：windows下，code::blocks
*/

#include <fstream>
using namespace std;

void WriteUtf8()
{
    wifstream input("input.txt"); // utf8编码
    wstring utf8bytes;
    getline(input, utf8bytes);

    wofstream output("output.txt");
    output << utf8bytes << endl;
}

int main()
{
    WriteUtf8();
}
