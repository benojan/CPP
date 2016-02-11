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
