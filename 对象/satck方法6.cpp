# include "stack.h"
Stack::Stack()//���ù��캯������һ����ջ
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
//item Ϊ��ǰջ��ָ����ָ����
bool Stack::push(const Item &item)
{
	if (top < MAX)
	{
		items[top++] = item;//��ջ
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item &item)
{
	if (top >0)
	{
		item=items[top--] ;//��ջ
		return true;
	}
	else
		return false;
}