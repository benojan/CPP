#include <iostream>
using namespace std;

int main()
{
    char c[10];
    string str;
    char ch;
    cin.getline(c,10); // 从cin流中读入一行不超过10个的字符，比如“string st\n”包括换行符在内的10个。当输入长度大于给定长度的时候会改变输入流的状态，导致下次输入失败，程序终止。
    cout << c << endl;

    cin.get(ch); //从cin流中读入1个字符到ch中。一个一个字符读，需要考虑最后的'\n'符。特别是连续使用的时候。
    cout << ch << endl;
    cin.get(ch);
    cout << ch << endl;
    
    cin.get(c, 3, 'a'); //从cin流中读入2个字符到c数组中，数组以'\0'结束。遇“换行符”自动结束，可以指定第三个参数更改结束符。
    cout << c << endl;

    // getline(cin, str); // 第一个参数是istream，第二个参数是string。一般用这个读取行比较好，这个是什么字符流？

}
