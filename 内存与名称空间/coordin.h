/*
头文件中常包含的内容：
！！！请不要将函数定义或变量声明加入头文件，除非函数内联，否则会重定义
1、函数原型
2、使用#define或const定义的符号常量
3、结构声明
4、类声明
5、模版声明
6、内联函数
*/
//*************关于头文件**********
/*
<文件名>：编译器将在存储标准头文件的主机系统的文件系统中查找
“文件名”：编译器将首先查找当前的工作目录或源代码目录
因此，在包含自己定义的头文件时用“头文件”。
*/
#ifndef COORDIN_H_//if not def:同一文件中只能使用一次
/*
以前没有使用预处理器编译指令#define定义COORDIN_H_时，才会
处理
#ifndef COORDIN_H_
……
#endif
之间的语句
*/
#define COORDIN_H_//之前未定义才能定义

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif