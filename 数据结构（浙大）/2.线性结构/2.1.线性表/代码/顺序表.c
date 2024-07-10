/********************************************************************************
* @File name:顺序表.c
* @Author: yxj
* @Date: 2023-8-7
* @Description:线性结构中顺序表(数组）的实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define SIZE 5
typedef struct LNode *List;
struct LNode{
	int Data[MAXSIZE];
	int Last;
};
/*
* Function: MakeEmpty
* Description: 结构体的初始化
* Input: None
* Output: None
* Returns: 初始化后的结构体 
*/
List MakeEmpty()
{
	List l;
	l=(List)malloc(sizeof(struct LNode));
	l->Last=-1;
	return l;
}
/*
* Function: Find
* Description: 查找元素
* Input: l: 查找的结构体
	 x: 要查找的元素
* Output: None
* Returns: 存储位置
*/
int Find(List l,int x)
{
	int i=0;
	while( i<=l->Last && l->Data[i]!=x)
		i++;
	if( i>l->Last)
	{
		printf("未找到\n");
		return -1;
	}else
		return i;
}
/*
* Function: Insert
* Description: 插入元素
* Input: l: 插入元素的结构体
	 x: 要插入的元素
	 p: 要插入的位置
* Output: None
* Returns:是否成功插入 
*/
int Insert( List l,int x,int p)
{
	int i;
	if(l->Last == MAXSIZE)
	{
		printf("表满\n");
		return 0;
	}
	if(p>l->Last || p<0)
	{
		printf("越界\n");
		return 0;
	}
	for(i=l->Last ; i>=p; i--)
		l->Data[i+1]=l->Data[i];
	l->Data[p]=x;
	l->Last++;
	return 1;
}
/*
* Function: Delete
* Description: 删除元素
* Input: l: 删除元素的结构体
	 p: 要删除的位置
* Output: None
* Returns:是否成功删除 
*/
int Delete(List l,int p)
{
	int i;
	if(p>l->Last || p<0)
	{
		printf("越界\n");
		return 0;
	}
	for( i=p ; i<=l->Last ; i++ )
		l->Data[i]=l->Data[i+1];
	l->Last--;
	return 1;
}
void main()
{
	int i;
	List l=MakeEmpty();
	for( i=0; i<SIZE; i++)
		scanf("%d",&(l->Data[i]));
	l->Last=i;
//	Insert(l,6,3);	// 插入测试
//	Delete(l,2);	
	for( i=0; i<l->Last; i++)
		printf("%d\t",l->Data[i]);
//	printf("查找位置为%d\n",Find(l,3));	//查找测试
	
}
