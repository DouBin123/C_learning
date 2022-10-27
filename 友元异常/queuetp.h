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
		Node(const Item &i) :item(i), next(0){}//将item成员初始化为i，将next指针设置为0
	private:
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	//preemptive(先发制人) definitions to prevent public copying,加上将会出错
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
	Node *add = new Node(item);//创建指针，并为指针所指内容分配内存、
	items++;
	if (front == 0)//空指针初始化
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
	Node *temp = front;//避免前一节点的内存以后不可用
	front = front->next;
	delete temp;
	if (items == 0)//无节点时，头指针赋为空指针
		rear = 0;
	return true;
}

#endif