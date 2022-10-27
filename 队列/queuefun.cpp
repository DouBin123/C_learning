# include "Queue.h"
# include <cstdlib>

//Queue method
Queue::Queue(int qs) :qsize(qs)
{
	front = rear = NULL;//or nullptr
	items = 0;
}
Queue::~Queue()//调用对象过期时删除队列
{
	Node *temp;
	while (front != NULL)//直到删除完节点为止
	{
		temp = front;
		front = front->next;
		delete temp;
	}

}
bool Queue::isempty()const
{
	return items == 0;

}
bool Queue::isfull()const
{
	return items == qsize;
}
int Queue::queuecount()const//调用该方法的对象不可以修改
{
	return items;
}
bool Queue::enqueue(const Item &item)//调用该方法的对象可以修改
{
	if (isfull())
		return false;
	Node * add = new Node;//为新加的节点分配内存
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)//front 指向第一个节点
		front = add;
	else
		rear->next=add;
	rear = add;
	return true;
}
bool Queue::dequeue(Item &item)//头尾皆要考虑
{
	if (front == NULL)
		return false;
	item = front->item;//头先出
	items--;
	Node* temp=front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}
//time aet to a random value in the range 1-3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;

}