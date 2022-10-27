# include "Queue.h"
# include <cstdlib>

//Queue method
Queue::Queue(int qs) :qsize(qs)
{
	front = rear = NULL;//or nullptr
	items = 0;
}
Queue::~Queue()//���ö������ʱɾ������
{
	Node *temp;
	while (front != NULL)//ֱ��ɾ����ڵ�Ϊֹ
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
int Queue::queuecount()const//���ø÷����Ķ��󲻿����޸�
{
	return items;
}
bool Queue::enqueue(const Item &item)//���ø÷����Ķ�������޸�
{
	if (isfull())
		return false;
	Node * add = new Node;//Ϊ�¼ӵĽڵ�����ڴ�
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)//front ָ���һ���ڵ�
		front = add;
	else
		rear->next=add;
	rear = add;
	return true;
}
bool Queue::dequeue(Item &item)//ͷβ��Ҫ����
{
	if (front == NULL)
		return false;
	item = front->item;//ͷ�ȳ�
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