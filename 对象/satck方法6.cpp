# include "stack.h"
Stack::Stack()//利用构造函数创建一个空栈
{
	top = 0;

}
bool Stack::isempty()const
{
	return  top == 0;
}
bool Stack::isfull() const
{
	return top == MAX;
}
//item 为当前栈顶指针所指数据
bool Stack::push(const Item &item)
{
	if (top < MAX)
	{
		items[top++] = item;//入栈
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item &item)
{
	if (top >0)
	{
		item=items[top--] ;//出栈
		return true;
	}
	else
		return false;
}