# hjqSTL
如果在Tops上看过且记得，那就是了
下面是用法原文

> 现在还是依托*山，等lzn来Pull Request他改过的版本

# 使用方法（必看！！！！！！！！！！）
## 第一种（小白用法）
在源程序同文件夹下把对应编码版本拖入，在引用时要使用`#include"hjqstl.h"`，==**注意一定是`"hjqstl.h"`，不是`<hjqstl.h>`！！！！！！！！！！**==
## 第二种（有点麻烦，且一次设置只对一个gcc有效）
打开要设置的MinGW32文件夹，打开lib文件夹，打开gcc文件夹，打开mingw32文件夹，打开MinGW版本号的文件夹，打开include文件夹
右键c++文件夹，点击属性，找到安全，点击编辑，点击添加，输入Everyone，点击检查名称，点击确定，点击Everyone，勾选允许完全控制，点击应用，关闭“c++ 的权限”，把只读关闭
打开c++文件夹，把对应编码版本拖入，改名为`hjqstl.h`，再在设置过的gcc引用时，可直接使用`#include<hjqstl.h>`，且不用考虑源程序的位置
