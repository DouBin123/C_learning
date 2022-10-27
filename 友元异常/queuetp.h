# ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
	enum{Q_SIZE=10};
	
	//Node is a nested class definition
	class Node
	{
	public:
		Item item;
		Node *next;
		Node(const Item &i) :item(i), next(0){}//��item��Ա��ʼ��Ϊi����nextָ������Ϊ0
	private:
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	//preemptive(�ȷ�����) definitions to prevent public copying,���Ͻ������
	//QueueTP(const QueueTP &q) :qsize(0){}
	//QueueTP &operater = (const QueueTP & q){ return *this; }

public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty()const
	{
		return items == 0;
	}
	bool isfull()const
	{
		return items == qsize;
	}
	int queuecount()const
	{
		return items;
	}
	bool enqueue(const Item &item);
	bool dequeue(Item & item);
};
//QueueTP method
template <class Item>
QueueTP<Item>::QueueTP(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node *temp;
	while (front != 0)//while queue is not yet empty
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
 
//add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
	if (isfull())
		return false;
	Node *add = new Node(item);//����ָ�룬��Ϊָ����ָ���ݷ����ڴ桢
	items++;
	if (front == 0)//��ָ���ʼ��
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node *temp = front;//����ǰһ�ڵ���ڴ��Ժ󲻿���
	front = front->next;
	delete temp;
	if (items == 0)//�޽ڵ�ʱ��ͷָ�븳Ϊ��ָ��
		rear = 0;
	return true;
}

#endif