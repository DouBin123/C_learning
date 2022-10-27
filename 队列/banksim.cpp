# include <iostream>
# include "Queue.h"
# include <cstdlib>
# include <ctime>
const int MIN_PER_HR = 60;

bool newcustomer(double x);//is there a new customer?

int main()
{
	using namespace std;
	srand(time(0));
	cout << "Case Study: Bank of HEILUN automatic teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);//default construction

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per minutes
	long cyclelimit = MIN_PER_HR*hours;//of cycle

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;//average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;//customer
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	//running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))//there are customers
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//设置顾客属性，arrive=cycle,processtime=(0~3)
				line.enqueue(temp);//进队
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);//出队
			wait_time = temp.ptime();//processtime
			line_wait += cycle - temp.when();//arrive,当前时间-来的时间
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();//人数
	}
	if (customers > 0)
	{
		cout << "customers accepted:　" << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "     turnaways: " << turnaways << endl;
		cout << " average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";

	}
	else
		cout << " No customers!\n";
	cout << "Done!\n";
	system("pause");
	return 0;
}
bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);

}//rand() / RAND_MAX=(0~n)/n<1,0<rand()*x / RAND_MAX<6
//这里认为到达的间隔时间小于1无效