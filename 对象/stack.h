#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private :
	enum{MAX=10};//constant specicial to class
	Item items[MAX];
	int top;
public:
	Stack();//默认构造函数
	bool isempty() const;
	bool isfull()const;
	//push() returns false if stack is full,true others
	bool push(const Item & item);
	//pop() returns false if stack already is empty
	bool pop(Item &item);
};


#endif