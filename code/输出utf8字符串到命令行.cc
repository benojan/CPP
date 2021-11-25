/**
* 功能：输出utf-8字符串到命令行
* 环境：visual studio 2022, Clang 编译器
*/

#include <iostream>
using namespace std;

int main()
{
    string u8bytes = "你好𣍐";
    system("chcp 65001");
    system("cls");
    cout << u8bytes << endl;
}
