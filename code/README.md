# 参考资料
- https://blog.csdn.net/whl0071/article/details/125677678 [c++程序编码]⭐
- https://blog.csdn.net/qq981091829/article/details/114121785 [UTF16及GB18030编码介绍]
- http://blog.csdn.net/haiross/article/details/45074355 [C++中的locale设置（即系统区域设置）]
- http://blog.csdn.net/wallaceli1981/article/details/6116738 [C++ 标准库的 locale 类用法]
- https://gcc.gnu.org/onlinedocs/libstdc++/manual/localization.html [libstd c++ localization章节]

----

# 最重要的概念

### 一、程序相关的编码

1. 程序源文件编码 
    程序源文件编码是指保存程序源文件内容所使用的编码方案，该编码方案可在保存文件的时候自定义。 
    通常在简体中文windows环境下，各种编辑器（包括visual studio）新建文件缺省编码都是GB18030，所以不特别指定的话，windows环境下的c++源文件的编码通常为GB18030（GB18030兼容GBK）；在linux环境下，默认的为UTF-8编码。

2. c++程序内码 
    源程序编译后，c++中的字符串常量变成一串字节存放在可执行文件中，内码指的是在可执行文件中，字符串以什么编码进行存放。这里的字符串常量指的是窄字符(char)而不是宽字符(wchar_t)。宽字符通常都是以Unicode（VC使用UTF-16BE, gcc使用UTF-32BE）存放。 
    通常简体中文版的VC使用内码为GB18030，而gcc使用内码缺省为UTF-8，单可以通过-fexec-charset参数进行修改。（可以通过在程序中打印字符串中每个字节的16进制形式来判断程序使用的内码）。

3. 运行环境编码 
    运行环境编码指的是，执行程序时，操作系统或终端所使用的编码。程序中输出的字符最终要转换为运行环境编码才能显示，否则就会出现乱码。 
    常用的简体中文版的windows环境编码是GB18030，linux下最常用的环境编码是UTF-8。
    
### 二、已知的问题

> windows下，VC默认使用UTF-16BE，wchar_t 不支持生僻字，使用普通的char就能支持utf-8。

----

确定一个locale,需要采用以下字符串格式：
```c
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
```
