//ѭ�����еļ�ʵ����Ӧ��,���ߴθĽ�ʵ�飬���ǰһ���汾�Ĳ����������
//ʵ����:2-2-2
//�༭����2016-5-20
//ʵ�ַ�ʽ���������±��ʶ����Ԫ�ص�λ�á�
//��һ�α��ʧ�ܣ������޷�����
#include<stdio.h>
#include<stdlib.h>

#ifndef CQueue_1
typedef int ElementType;
#define OK 1
#define ERROR 0
#define CQueue_Size_Max 100
typedef struct CQueue
{
	int* Elem;
	ElementType Front;//�����±�
	ElementType Rear;//�����±�
}CQueue_Pointor;
ElementType Creat_CQueue(CQueue_Pointor &q);
ElementType Display_CQueue(CQueue_Pointor q);//��ӡ��ǰ��ѭ������
ElementType Enter_CQueue(CQueue_Pointor &q, int e);//��ԭ����ѭ�������в���һ���µ�ֵ
ElementType  Delet_CQueue(CQueue_Pointor &q);//��ԭ�е�ѭ��������ɾ��һ��Ԫ��
int CQueue_Length(CQueue_Pointor q);//�����ǰ��ѭ������Ĵ�С
#endif // !CQueue

int main()
{
	CQueue_Pointor q;//���ò��������⣬��Ӧ��ָ��ṹ���ָ�룬��Ӧ���ǽṹ�壬�޸������2-2-2�汾
	int element, e;
	Creat_CQueue(q);
	printf("Please input the numbers to combine the queue\n");
	printf("you can input the 0 to quit\n");
	scanf_s("%d", &e);
	while (e)
	{
		Enter_CQueue(q, e);
		printf("Please input the numbers to combine the queue""  0 to quit\n");
		scanf_s("%d", &e);
	}
	printf("The queue is \n");
	Display_CQueue(q);
	printf("delet the frist number of the queue\n");
	element = Delet_CQueue(q);
	printf("the frist number is %d\n", element);
	printf("The new queue is \n");
	Display_CQueue(q);
	return OK;
}

ElementType Creat_CQueue(CQueue_Pointor &q)
{
	q.Elem=(int*)malloc(CQueue_Size_Max * sizeof(CQueue_Pointor));
	if (!q.Elem)
	{
		printf("OVERFLOW.the program is wrong\n");
		return ERROR;
	}
	q.Front = q.Rear = -1;
	for (int i = 0; i < CQueue_Size_Max; i++)//�����������
	{
		/*********************************************************/
		q.Elem[i] = -1;//����ص㣬�ڴ��޷�д��
						/********************************************************/
	}
	return OK;
}

ElementType Display_CQueue(CQueue_Pointor q)
{
	for (int i = 0; i < CQueue_Length(q); i++)
	{
		if (q.Elem[i] != -1)
			printf("%d  ", q.Elem[i]);
	}
	printf("\n");
	return OK;
}
ElementType Enter_CQueue(CQueue_Pointor &q, int e)
{
	q.Rear = (q.Rear + 1) % CQueue_Size_Max;
	if (q.Rear == q.Front)//����������Ϊʹ��=������==
	{
		printf("the queue is full\n");
		return ERROR;
	}
	q.Elem[q.Rear] = e;
	return OK;
}
ElementType Delet_CQueue(CQueue_Pointor &q)//���Ӻ�����������
{
	int e;//�����洢����ɾ���ĵ�һ��Ԫ��
	e = q.Elem[q.Front + 1];
	q.Elem[q.Front + 1] = -1;
	q.Front = (q.Front + 1) % CQueue_Size_Max;
	return OK;
}
int CQueue_Length(CQueue_Pointor q)
{
	return (q.Rear - q.Front + CQueue_Size_Max) % CQueue_Size_Max;
}