# ifndef STACKTP_H_
# define STACKTP_H_

template <class Type>
class Stack
{
private:
	enum {MAX=10};//constant specific to class
	Type items[MAX];//hold stack items
	int top;
public:
	Stack();//默认构造函数
	bool isempty() const;
	bool isfull()const;
	//push() returns false if stack is full,true others
	bool push(const Type & item);
	//pop() returns false if stack already is empty
	bool pop(Type &item);
};

template<class Type>
Stack <Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack <Type>::isempty()const
{
	return top == 0;
}

template<class Type>
bool Stack <Type>::isfull()const
{
	return top == MAX;
}

template<class Type>
bool Stack <Type>::push(const Type &item)
{
	if (top < MAX)
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



#endif