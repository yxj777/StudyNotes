/********************************************************************************
* @File name:链式队列.c
* @Author: yxj
* @Date: 2023-9-9
* @Description:线性结构中链式队列的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
struct QNode
{
	int Data;
	struct QNode *Next;
};
typedef struct QNode *Queue;
struct Qp
{
	Queue rear;	//队列的尾结点
	Queue front;	//队列的头结点
};
typedef struct Qp *Quep;
/*
* Function: CreateQueue
* Description: 创建并初始化头结点
* Input: None
* Output: None
* Returns: 返回创建的头结点
*/
Quep CreatQueue()
{
	Quep q=(Quep)malloc(sizeof(struct Qp));
	q->rear=NULL;		
	q->front=NULL;
	return q;
}
/*
* Function: IsEmptyQ
* Description: 判断队列是否为空
* Input: q:判断的队列
* Output: None
* Returns: 队列空为1，未空为0
*/
int InEmptyQ(Quep q)
{
	if(q->front==NULL)
	{
		return 1;
	}
	return 0;
}
/*
* Function: addQ
* Description: 入列
* Input: q: 入列的队列
	 x: 入列的元素
* Output: None
* Returns: None
*/
void addQ(Quep q,int x)
{
	Queue add=(Queue)malloc(sizeof(struct QNode));
	add->Next=NULL;
	add->Data=x;
	if(InEmptyQ(q))
	{
		q->front=add;	
		q->rear=add;
	}else
	{
		q->rear->Next=add;
		q->rear=add;	
	}
}
/*
* Function: DelQ
* Description: 出列
* Input: s: 出列的队列
	 x: 出列的元素
* Output: None
* Returns: 出列的元素
*/
int DelQ(Quep q)
{
	Queue t;
	int x=q->front->Data;
	if(InEmptyQ(q))
	{	
		printf("队列空");
		return NULL;	
	}
	t=q->front;
	if(q->front==q->rear)
		q->front=q->rear=NULL;
	else
		q->front=q->front->Next;
	free(t);
	return x;
}
void main()
{
	int i,x;
	Quep q=CreatQueue();
	for(i=0; i<MaxSize; i++)	//测试addQ
	{
		scanf("%d",&x);
		addQ(q,x);
	}
	for(i=0; i<=MaxSize-1; i++)	//测试DelQ
	{
		x=DelQ(q);
		printf("%d",x);
	}
}
