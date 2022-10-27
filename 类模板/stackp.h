# ifndef STACKP1_H_
# define STACKP1_H_

template <class Type>
class Stack
{
private:
	enum { MAX = 10 };//constant specific to class
	Type *items;//hold stack items
	int stacksize;//栈的尺寸，可容纳同一类型数据的数量
	int top;
public:
	explicit Stack(int ss=MAX);//构造函数
	Stack(const Stack &st);
	~Stack(){ delete[] items; };
	bool isempty() { return top == 0; };
	bool isfull(){ return top == stacksize; };
	//push() returns false if stack is full,true others
	bool push(const Type & item);
	//pop() returns false if stack already is empty
	bool pop(Type &item);
	Stack &operator=(const Stack &st);
};

template<class Type>
Stack <Type>::Stack(int ss) :stacksize(ss), top(0)
{
	items = new Type[stacksize];//为栈中所要存储的地址所指向的值分配地址
}

template<class Type>
Stack <Type>::Stack(const Stack &st) 
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}


template<class Type>
bool Stack <Type>::push(const Type &item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<class Type>
bool Stack <Type>::pop(Type &item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
template<class Type>
Stack <Type>& Stack <Type>::operator=(const Stack<Type> &st)
{
	if (this == &st)
		return *this;
	delete[]items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

#endif