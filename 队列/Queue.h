# ifndef QUEUE_H_
#define QUEUE_H_

class Customer//������нڵ����Ϣ����
{
public:

	Customer(){ arrive = processtime = 0; }
	void set(long when);
	long when()const{ return arrive; }
	int ptime()const{ return processtime; }	
private:
	long arrive;//arrive time for customer
	int processtime;//process time for customer
};
typedef Customer Item;//rename

class Queue
{

private:
	struct Node
	{
		Item item;
	    Node *next;
	};
	enum{ Q_SIZE = 10 };
	Node * front;//pointer to front of Queue
	Node * rear;//pointer to rear of Queue
	int items;
	const int qsize;

	//preemptive(�ȷ�����) definitions to prevent public copying
	Queue(const Queue &q) :qsize(0){}
	Queue &operator=(const Queue &q){ return *this; }
public:
	Queue(int qs=Q_SIZE);//create queue with a qs limit
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item &item);//add item to end
	bool dequeue(Item &item);//remove item from front
};

#endif