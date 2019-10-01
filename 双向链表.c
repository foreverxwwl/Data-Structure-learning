#include<stdio.h>
#include<stdlib.h>
#include"双向链表.h"

//双向链表初始化，传入的是头指针l的地址
void initList(LinkList * l)
{
	(*l) = (Node *)malloc(sizeof(Node));
	//一定要将尾节点指针域赋空，在以后移动指针判断操作才不会出现空指针异常
	(*l)->next = NULL;//后指针指空
	(*l)->piror = NULL;//前指针指空
	(*l)->data = NULL;//将其data域赋为空，可区分头结点
}

//建立新链表，输入要插入的内容，以-1结束
void creatFormTail(LinkList l)
{
	Node * r = l;//移动的指针
	Node * s;//指向新建的节点
	int c;//新节点data域
	int flag = 1;
	while (flag)
	{
		scanf("%d", &c);
		if (c != -1)
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = r->next;//新节点的后指针赋空
			s->piror = r;
			r->next = s;
			r = r->next;
		}
		else
		{
			flag = 0;
		}
	}
}

//在循环链表l的第i个元素前插入一个节点
void lnslist(LinkList l, int i, int data)
{
	Node * r, *s;
	int j = 0;
	r = l;
	//首先判断插入位置是否合法
	if (i <= 0)
	{
		//插入位置小于1
		printf("查找序号不合法");
		return NULL;
	}
	//寻找插入位置
	while ((r != NULL) && j<i)
	{
		r = r->next;
		j++;
	}
	if (r == NULL)
	{
		//插入位置大于链表长度
		printf("查找序号不合法");
		return NULL;
	}
	s = (Node *)malloc(sizeof(Node));
	s->data = data;
	s->piror = r->piror;//插入节点前指针指向前一节点
	r->piror->next = s;//插入节点前一节点后指针指向插入节点
	s->next = r;//插入节点与后节点双向联通
	r->piror = s;
}

//删除第i个元素，并将该元素内容存入data中
void deleteList(LinkList l, int i, int * data)
{
	Node * r = l;
	int j = 0;
	if (i <= 0)
	{
		//删除位置小于1
		printf("查找序号不合法");
		return NULL;
	}
	//寻找删除位置
	while (r != NULL && j < i)
	{
		r = r->next;
		j++;
	}
	if (r == NULL)
	{
		//删除位置大于链表长度
		printf("查找序号不合法");
		return NULL;
	}
	//修改指针删除
	r->piror->next = r->next;//使前一个节点尾指针指向后一个节点
	r->next->piror = r->piror;//使后一个节点的头指针指向前一个节点
	*data = r->data;
	free(r);
}

//链表复制,返回复制后链表
LinkList cloneList(LinkList l)
{
	Node * r = l->next;//定义一个指向原链表的移动指针
	Node * p;//定义一个指向新链表的移动指针
	LinkList s, l2;//s指向是新建立的节点，l2为新链表的头指针
	initList(&l2);
	p = l2;//将p指向头，方便尾插法建表
	while (r != NULL)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = r->data;//给新节点复制值
		r = r->next;//指向原链表下一个待复制位置
		s->next = p->next;//新节点的后指针赋空
		s->piror = p;
		p->next = s;
		p = p->next;//p指向新最新节点
	}
	return l2;
}
//链表输出
void printList(LinkList l)
{
	Node * r = l->next;
	while (r != NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
	printf("\n");
}
//主函数
int main(void)
{
	LinkList l;
	Node * s;
	int data;
	initList(&l);
	creatFormTail(l);//建立链表
	printList(l);
	deleteList(l, 2, &data);//删除链表元素
	printList(l);
	s = cloneList(l);//复制l链表
	printList(s);
	return 0;
}
