/********************************************************************************
* @File name:顺序队列.c
* @Author: yxj
* @Date: 2023-9-9
* @Description:线性结构中顺序堆栈的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
struct QNode
{
	int Data[MaxSize];	
	int front;		//队列的头指针
	int rear;		//队列的尾指针
};
typedef struct QNode *Queue;
/*
* Function: CreateQueue
* Description: 创建并初始化队列
* Input: None
* Output: None
* Returns: 返回创建的队列
*/
Queue CreatQueue()
{
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->front=q->rear=-1;
	return q;
}
/*
* Function: IsFullQ
* Description: 判断队列是否为满
* Input: q:判断的队列
* Output: None
* Returns: 队列满为1，未满为0
*/
int IsFullQ(Queue q)
{
	if((q->rear+1)%MaxSize == q->front)
	{
		printf("队列已满");
		return 1;
	}
	return 0;
}
/*
* Function: IsEmptyQ
* Description: 判断队列是否为空
* Input: q:判断的队列
* Output: None
* Returns: 队列空为1，未空为0
*/
int IsEmptyQ(Queue q)
{
	if(q->rear==q->front)
	{
		printf("队列空");
		return 1;
	}
	return 0;
}
/*
* Function: addQ
* Description: 入列
* Input: s: 入列的队列
	 x: 入列的元素
* Output: None
* Returns: None
*/
void addQ(Queue q,int x)
{
	if(IsFullQ(q))	//判断队列是否满
		return;
	q->rear=(q->rear+1)%MaxSize;
	q->Data[q->rear]=x;
	return;
}
/*
* Function: DelQ
* Description: 出列
* Input: s: 出列的队列
	 x: 出列的元素
* Output: None
* Returns: 出列的元素
*/
int DelQ(Queue q)
{
	int x;
	if(IsEmptyQ(q))
		return NULL;
	q->front=(q->front+1)%MaxSize;
	x=q->Data[q->front];
	return x;	
}
void main()
{
	int i,x;
	Queue q=CreatQueue();
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
