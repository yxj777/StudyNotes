/********************************************************************************
* @File name:链序表.c
* @Author: yxj
* @Date: 2023-8-8
* @Description:线性结构中链式表(链表）的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef struct LNode *List;
struct LNode{
	int Data;
	List Next;
};

List Find(List l,int x)
{
	List head=l;
	while( head && head->Data!=x )
		head=head->Next;
	return head;
}
//void addList(List *l,int x)
//{
//	List s=(List)malloc(sizeof(struct LNode));
//	s->Data=x;
//	s->Next=NULL;
//	if(*l==NULL)	//如果没有元素
//	{
//		*l=s;
//	}
//	else
//		(*l)->Next=s;
//}
int Inster(List l,int x,int p)
{
	List t=l,head;
	int i;
	if(!p)	//在开头插入
	{
		head=(List)malloc(sizeof(struct LNode));
		head->Data=x;
		head->Next=l;
		return 1;			
	}
	for( i=0 ; i<p; i++)
		t=t->Next;
	if(t)
	{
		printf("越界");
		return 0;
	}
	head=(List)malloc(sizeof(struct LNode));
	head->Data=x;
	head->Next=t->Next;
	t->Next=head;
	return 1;
}

int Delete(List l,int p)
{
	List t=l,s;
	int i;
	if (!p)
	{
		if(l!=NULL)
			l=l->Next;
		else 
			return 0;
		free(t);
		return 1;
	}
	for( i=0 ; i<p-1; i++)
		t=t->Next;
	if (t==NULL)
	{	
		printf("不存在");
		return 0;		
	}else if( t->Next==NULL )
	{
		printf("不存在");
		return 0;
	}else 
	{
		s=t->Next;
		t->Next=s->Next;
		free(s);
		return 1;
	}
	
	

}
void main()
{
//	int i,x;
//	List l=NULL;
//	printf("请输入数字\n");
//	for(i=0; i<MAXSIZE; i++)
//	{
//		scanf("%d",&x);
//		addList(&l,x);
//	}
//	while(l)
//	{
//		printf("%d\t",l->Data);
//		l=l->Next;
//	}
}
