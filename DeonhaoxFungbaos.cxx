#include <iostream>
#include <locale>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <exception>
using namespace std;

locale loc("zh_CN.UTF-8");
int main(int argc, char* argv[])
{
    try {
        locale::global(loc);
        cout << loc.name() << endl;
        wstring ws = L"中国";//"\x4F60\x597D\x554A";
        wcout << ws << endl;
    }
    catch(runtime_error& e)
    {
        cerr << "Error:" << e.what() << endl;
        cerr << "Type:" << typeid(e).name() << endl;
    }
    //printf("%x", ws[0]);
    //wcout << hex << ws[0] << endl;
    //string fileName = "C:\\Users\\Administrator\\Desktop\\hello.txt";
    //wofstream wout(fileName);
    //wout << ws << endl;
    //wout.close();
}


#include <iostream>
#include <locale>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <exception>
using namespace std;

int main(int argc, char* argv[])
{
    //cout << loc.name() << endl;
    //wstring ws = L"\x4F60\x597D\x554A";//"\x4F60\x597D\x554A";
    //wcout << ws << endl;
  char ch1 = 't';
  wchar_t ch2 = L'\x4F60'; // 最好用unicode编码的十六进制表示汉字！
  cout << hex << (int) ch1 << " " << ch2 << endl; //output:74 4f60------即输出成功
  wcout << hex << (int) ch1 << L" " << ch2 << endl; //output:74 --------前面输出成功，后面输出失败

    //printf("%x", ws[0]);
    //wcout << hex << ws[0] << endl;
    //string fileName = "C:\\Users\\Administrator\\Desktop\\hello.txt";
    //wofstream wout(fileName);
    //wout << ws << endl;
    //wout.close();
}
