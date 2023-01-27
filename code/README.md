# 参考资料
- ⭐https://blog.csdn.net/whl0071/article/details/125677678 [c++程序编码]
- http://blog.csdn.net/haiross/article/details/45074355 [C++中的locale设置（即系统区域设置）]
- http://blog.csdn.net/wallaceli1981/article/details/6116738 [C++ 标准库的 locale 类用法]
- https://gcc.gnu.org/onlinedocs/libstdc++/manual/localization.html [libstd c++ localization章节]

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
