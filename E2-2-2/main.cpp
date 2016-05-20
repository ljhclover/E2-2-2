//循环队列的简单实现与应用,第七次改进实验，解决前一个版本的参数混乱情况
//实验编号:2-2-2
//编辑日期2016-5-20
//实现方式采用数组下标标识现在元素的位置。
//第一次编程失败，程序无法运行
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
	ElementType Front;//数组下标
	ElementType Rear;//数组下标
}CQueue_Pointor;
ElementType Creat_CQueue(CQueue_Pointor &q);
ElementType Display_CQueue(CQueue_Pointor q);//打印当前的循环队列
ElementType Enter_CQueue(CQueue_Pointor &q, int e);//在原来的循环链表中插入一个新的值
ElementType  Delet_CQueue(CQueue_Pointor &q);//在原有的循环链表中删除一个元素
int CQueue_Length(CQueue_Pointor q);//输出当前的循环链表的大小
#endif // !CQueue

int main()
{
	CQueue_Pointor q;//设置参数有问题，不应是指向结构体的指针，而应该是结构体，修改问题见2-2-2版本
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
	for (int i = 0; i < CQueue_Size_Max; i++)//清除数组内容
	{
		/*********************************************************/
		q.Elem[i] = -1;//错误地点，内存无发写入
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
	if (q.Rear == q.Front)//发生错误因为使用=而不是==
	{
		printf("the queue is full\n");
		return ERROR;
	}
	q.Elem[q.Rear] = e;
	return OK;
}
ElementType Delet_CQueue(CQueue_Pointor &q)//出队函数存在问题
{
	int e;//用来存储即将删除的第一个元素
	e = q.Elem[q.Front + 1];
	q.Elem[q.Front + 1] = -1;
	q.Front = (q.Front + 1) % CQueue_Size_Max;
	return OK;
}
int CQueue_Length(CQueue_Pointor q)
{
	return (q.Rear - q.Front + CQueue_Size_Max) % CQueue_Size_Max;
}