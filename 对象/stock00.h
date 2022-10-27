#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private  ://�������أ�ֻ��ͨ��������Ա�����ʣ����Է�ֱֹ�ӷ��ʳ�Ա
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares*share_val; }
	//���������ж���ĺ�������ֱ�ӳ�Ϊ��������
public://�����ӿڵ����Ա
	Stock();//Ĭ�Ϲ��캯��
	Stock(const std::string &co, long n = 0, double pr = 0.0);//���ع��캯��
	~Stock();//��������
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;//ȷ�����ö���ֵ�����޸�
	const Stock & topval(const Stock &s)  const;//(const Stock &s):��ʽ����һ����������ã�����.topval():��ʽ������һ���󣨸ö�������˳�Ա������
};



#endif