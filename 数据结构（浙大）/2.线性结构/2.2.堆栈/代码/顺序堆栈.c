/********************************************************************************
* @File name:堆栈顺序表.c
* @Author: yxj
* @Date: 2023-9-7
* @Description:线性结构中堆栈顺序表(数组）的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
struct SNode{
	int Data[MaxSize];
	int top;
};
/*
* Function: CreateStack
* Description: 创建结构体
* Input: None
* Output: None
* Returns: 返回创建的结构体
*/
typedef struct SNode *Stack;
Stack CreateStack()
{
	Stack s;
	s=(Stack)malloc(sizeof(struct SNode));
	s->top=-1;
	return s;
}
/*
* Function: Push
* Description: 压栈
* Input: s:压入元素的结构体
	 item: 要压入的元素
* Output: None
* Returns: None
*/
void Push(Stack s,int item)
{
	if( s->top== MaxSize-1)
		printf("堆栈满");
	else 
		s->Data[++(s->top)]=item;
	return;
}
/*
* Function: Pop
* Description: 出栈
* Input: s: 出栈元素的结构体
* Output: None
* Returns: int:出栈的元素
*/
int Pop(Stack s)
{
	if( s->top == -1 )
	{
		printf("堆栈空");
		return NULL;
	}
	else
		return s->Data[(s->top)--];	
}
void main()
{
	int i,x;
	Stack s=CreateStack();
	for(i=0; i<5; i++)
	{
		scanf("%d",&x);
		Push(s,x);
	}
	for(i=0; i<=4; i++)
	{
		x=Pop(s);
		printf("%d",x);
	}
}
