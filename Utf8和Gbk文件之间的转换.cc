/**
* 该代码适用于windows平台下
*/

#include <iostream>
#include <fstream>
#include <codecvt>
#include <string>
using namespace std;

// utf8 => gbk
void Utf8ToGbk()
{
    // 读取utf8文件
    // input.txt的编码为utf8
    ifstream input("input.txt");
    string utf8code;
    getline(input, utf8code);

    // 转换成unicode
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring unicode = conv.from_bytes(utf8code);

    // 转换成gbk
    // linux下 "zh_CN.GBK"
    // windows下 ".936"
    auto codecvt_gbk = new codecvt_byname<wchar_t, char, mbstate_t>(".936");
    wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> gbk(codecvt_gbk);
    string gbkcode = gbk.to_bytes(unicode);

    // 输出gbk
    cout << gbkcode << endl;
}

// gbk => utf8
void GbkToUtf8()
{
    // 读取gbk文件
    // input.txt的编码为gbk
    ifstream input("input.txt");
    string gbkcode;
    getline(input, gbkcode);

    // 转换成unicode
    // linux下 "zh_CN.GBK"
    // windows下 ".936"
    auto codecvt_gbk = new codecvt_byname<wchar_t, char, mbstate_t>(".936");
    wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> gbk(codecvt_gbk);
    wstring unicode = gbk.from_bytes(gbkcode);

    // 转换成utf8
    wstring_convert<codecvt_utf8<wchar_t>> utf8;
    string utf8code = utf8.to_bytes(unicode);

    // 写入utf8文件
    ofstream output("output.txt");
    output << utf8code;
}

int main()
{
    Utf8ToGbk();
}
