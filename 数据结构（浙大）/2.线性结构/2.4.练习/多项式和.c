/********************************************************************************
* @File name:多项式和.c
* @Author: yxj
* @Date: 2023-9-10
* @Description: 练习题，求多项式的和
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3
typedef struct Poly *List;
struct Poly
{
	int coef;	//系数
	int expon;	//指数
	List Next;
};
void Attach(int coef,int expon,List *rear)
{
	List s=(List)malloc(sizeof(struct Poly));
	s->coef=coef;
	s->expon=expon;
	s->Next=NULL;
	//将新节点接到多项式最后，并使rear指向新节点	
	(*rear)->Next=s;
	(*rear)=s;
}
int compare(int x,int y)
{
	int flag;
	if(x>y)
		flag=1;
	else if(x<y)
		flag=-1;
	else if(x==y)
		flag=0;
	return flag;	
}
List PolyAdd(List p1,List p2)
{
	List front,rear,tem;
	front=rear=(List)malloc(sizeof(struct Poly));
	int sum;
	while(p1 && p2)	//p1 p2是否不为空
	{
		switch(compare(p1->expon,p2->expon))
		{
			case 1:		//p1的指数大
				Attach(p1->coef,p1->expon,&rear);
				p1=p1->Next;
				break;
			case -1:	//p2的指数大
				Attach(p2->coef,p2->expon,&rear);
				p2=p2->Next;
				break;
			case 0:		//指数相同
				sum=p1->coef+p2->coef;	
				if(sum)
					Attach(sum,p1->expon,&rear);
				p1=p1->Next;
				p2=p2->Next;
				break;		
		}
	}
	//将未处理完的一项复制到结果多项式的尾处
	for( ;p1;p1=p1->Next) Attach(p1->coef,p1->expon,&rear);
	for( ;p2;p2=p2->Next) Attach(p2->coef,p2->expon,&rear);	
	rear->Next=NULL;	
	tem=front;
	front=front->Next;	//front指向多项式的第一项
	free(tem);		//释放临时头结点
	return front;
}
void scanfL(List s)
{
	int x,i;
	List p;
	for(i=0;i<MAXSIZE;i++)
	{
		p=(List)malloc(sizeof(struct Poly));	
		printf("请输入系数\n");
		scanf("%d",&x);
		p->coef=x;
		printf("请输入指数\n");
		scanf("%d",&x);
		p->expon=x;
		p->Next=NULL;

		s->Next=p;
		s=p;
	}	
}
void printfL(List s)
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		printf("%dX%d",s->coef,s->expon);
		s=s->Next;
	}	
	printf("\n");
}
void main()
{
	List p1,p2,sum;
	p1=(List)malloc(sizeof(struct Poly));
	p2=(List)malloc(sizeof(struct Poly));
	sum=(List)malloc(sizeof(struct Poly));
	printf("请输入第一个多项式\n");
	scanfL(p1);
	printf("请输入第二个多项式\n");	
	scanfL(p2);
	sum=PolyAdd(p1,p2);
	printf("多项式和为：");
	printfL(sum);
}
