/*
ͷ�ļ��г����������ݣ�
�������벻Ҫ����������������������ͷ�ļ������Ǻ���������������ض���
1������ԭ��
2��ʹ��#define��const����ķ��ų���
3���ṹ����
4��������
5��ģ������
6����������
*/
//*************����ͷ�ļ�**********
/*
<�ļ���>�����������ڴ洢��׼ͷ�ļ�������ϵͳ���ļ�ϵͳ�в���
���ļ������������������Ȳ��ҵ�ǰ�Ĺ���Ŀ¼��Դ����Ŀ¼
��ˣ��ڰ����Լ������ͷ�ļ�ʱ�á�ͷ�ļ�����
*/
#ifndef COORDIN_H_//if not def:ͬһ�ļ���ֻ��ʹ��һ��
/*
��ǰû��ʹ��Ԥ����������ָ��#define����COORDIN_H_ʱ���Ż�
����
#ifndef COORDIN_H_
����
#endif
֮������
*/
#define COORDIN_H_//֮ǰδ������ܶ���

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif