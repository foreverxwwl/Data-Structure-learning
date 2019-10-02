#include<stdio.h>
#include"静态链表.h"

//初始化静态链表,主要任务是让每一个节点cur指向下一个节点
void InitList(StaticList l)
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		l[i].cur = i + 1;
	}
	//备用链表的最后一个空元素的cur指向0，这样才可以再分配节点时判断是否已经存满
	l[MAXSIZE - 2].cur = 0;
	//最后一个节点是使用链的头结点，初始化为0；
	l[MAXSIZE - 1].cur = 0;
}

//在插入元素时，为带插入元素寻找一个空间下标
int Malloc(StaticList l)
{
	//l[0].cur代表下一个可以插入的位置
	int i = l[0].cur;
	if (i){//如果位置是0则不能插入
		//位置不是0，则在此位置插入，并且将其下一个位置赋给头
		l[0].cur = l[i].cur;
	}
	return i;
}

//删除元素时，将其位置保存，方便下次插入
void Free(StaticList l, int k)
{
	//将头中保存的下个可插入节点的位置赋给此待删除节点
	l[k].cur = l[0].cur;
	//将次待删除节点位置赋给头，通过这两部操作将此节点放入了待插入链
	l[0].cur = k;
}

//求静态链表中元素个数，不包括头尾节点
int ListLength(StaticList L)
{
	//L[MAXSIZE - 1]是已用链的头结点，.cur是已用链第一个节点位置
	int i = L[MAXSIZE - 1].cur;
	int j = 0;
	while (i)
	{
		j++;
		//不断查找到下一个已用链，最后一个已用链cur值为0
		i = L[i].cur;
	}
	return j;
}

//静态链表中i位置插入一个元素
void lnsertList(StaticList L, int i, int data)
{
	//判断插入点是否合理,要按照顺序插入不能跳跃插入
	if (i<1 || i>ListLength(L) + 1)
	{
		printf("插入点不合理");
		return;
	}
	int j = Malloc(L);//分配到插入位置
	int k = MAXSIZE - 1;//k表示已用链头结点
	if (j)
	{
		//循环让k指向待插入位置i的已用链中前一个位置
		for (int l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].data = data;
		//将新节点与上一个节点连接
		L[j].cur = L[k].cur;
		//将新节点与下一个节点连接
		L[k].cur = j;
	}
}

//删除第i个元素，将值放入data中
void DeleteList(StaticList L, int i, int *data)
{

	if (i < 1 || i >= ListLength(L))
	{
		printf("删除位置不合法");
		return;
	}
	//k指向已用链头结点
	int k = MAXSIZE - 1;
	//循环让k指向已用链中k待删除节点的上一个节点
	for (int l = 1; l <= i - 1; l++)
	{
		k = L[k].cur;
	}
	//j指向待删除节点
	int j = L[k].cur;
	*data = L[j].data;
	//将上一个节点与下一个节点相连
	L[k].cur = L[j].cur;
	//将本节点置空加入备用链
	Free(L, j);
}

//输出链表
void printList(StaticList L)
{
	//k指向已用链头结点
	int k = MAXSIZE - 1;
	//已用链的cur不为0时输出
	while (L[k].cur)
	{
		k = L[k].cur;
		printf("%d ", L[k].data);
	}
	printf("\n");
}

int main(void)
{
	StaticList L;
	int j = 0;
	int data;
	InitList(L);
	printf("输入元素，以-1结尾\n");
	while (1)
	{
		scanf("%d", &data);
		if (data != -1)
		{
			j++;
			lnsertList(L, j, data);
		}
		else
		{
			break;
		}
	}
	printList(L);
	DeleteList(L, 2, &data);
	printf("删除的元素值为 %d\n", data);
	printList(L);
	return 0;
}