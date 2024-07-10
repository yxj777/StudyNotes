/********************************************************************************
* @File name:堆栈链式表.c
* @Author: yxj
* @Date: 2023-9-8
* @Description:线性结构中堆栈链式表(数组）的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct SNode *Stack;
struct SNode{
	int Data;
	Stack Next;
};
/*
* Function: CreateStack
* Description: 创建结构体
* Input: None
* Output: None
* Returns: 返回创建的结构体
*/
Stack CreateStack()
{
	Stack s;
	s=(Stack)malloc(sizeof(struct SNode));
	s->Next=NULL;
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
void Push(Stack s,int x)
{
	Stack t;
	t=(Stack)malloc(sizeof(struct SNode));
	t->Data=x;
	t->Next=s->Next;
	s->Next=t;
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
	Stack t;
	int x;
	if(s->Next==NULL)
	{
		printf("堆栈空");
		return NULL;
	}else
	{
		t=s->Next;
		s->Next=t->Next;
		x=t->Data;
		free(t);
		return x;
	}
}
void main()
{
	int i,x;
	Stack s=CreateStack();
	for(i=0; i<5; i++)	//测试Push
	{
		scanf("%d",&x);
		Push(s,x);
	}
	for(i=0; i<=4; i++)	//测试Pop
	{
		x=Pop(s);
		printf("%d",x);
	}
}
