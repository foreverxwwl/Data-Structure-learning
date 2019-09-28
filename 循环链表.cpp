#include<stdio.h>
#include<stdlib.h>

//循环链表
typedef struct Node{
	int data;
	struct Node * next;
}Node, *LinkList;

//初始化
void InitList(LinkList * l)
{
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = *l;//将尾节点的指针域指向头结点
	(*l)->data = NULL;//将头结点的Data域赋为空，借此区分头结点和其他节点
}

//链表建立，尾插法建立新链表
void creatList(LinkList l)
{
	int data;
	Node * s;//申明一个新建节点
	Node * r = l;//申明一个移动节点
	while (true)
	{
		scanf("%d", &data);
		if (data != -1)
		{
			s = (Node *)malloc(sizeof(Node));
			s->data = data;
			r->next = s; //修改指针
			s->next = l;
			r = r->next;
		}
		else{
			break;
		}
	}
}

//增加新节点，在i位置插入值为Data的节点
void InsertNode(LinkList l, int i, int data)
{
	Node * r = l;
	Node * p = l;
	Node * s;
	int j = 0;
	if (i <= 0)//判断插入位置
	{
		printf("插入位置小于1");
		return;
	}
	//移动p节点，p节点是待删除节点的前一个节点
	while (p->next->next != l && j != i - 1)
	{
		p = p->next;
		j++;
	}
	r = p->next;
	if (r == l)
	{
		printf("找不到待插入位置");
		return;
	}
	//新建节点并插入
	s = (Node *)malloc(sizeof(Node));
	s->data = data;
	p->next = s;
	s->next = r;
}

//删除节点，删除第i个节点
void deleteList(LinkList l, int i)
{
	Node * r = l;
	Node * p = l;
	int j = 0;
	if (i <= 0)
	{
		printf("删除位置小于1");
		return ;
	}
	//移动p节点，p节点是待删除节点的前一个节点
	while (p->next->next != l && j != i - 1)
	{
		p = p->next;
		j++;
	}
	r = p->next;
	if (r == l)
	{
	    printf("找不到待删除节点");
		return;
	}
	//直接删除，不影响头结点和尾指针
	p->next = r->next;
	free(r);
}

//查找节点，查找第i个节点
Node * gitNode(LinkList l, int i)
{
	Node * r = l;
	int j = 0;
	if (i <= 0)
	{
		printf("查找位置小于1");
		return NULL;
	}
	while (r->next != l && j != i)
	{
		r = r->next;
		j++;
	}
	if (r == l)
	{
		printf("找不到待查找节点");
		return NULL;
	}
	return r;
}

//输出链表
void printList(LinkList l)
{
	l = l->next;
	while (l->data != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}

int main(void)
{
	LinkList l;
	Node * s;
	InitList(&l);//初始化链表
	creatList(l);//建立新链表
	printList(l);
	InsertNode(l, 3, 5);//在3位置插入值5
	printList(l);
	deleteList(l, 2);//删除2节点
	printList(l);
	s = gitNode(l, 4);//查找4节点
	printf("%d", s->data);
	return 0;
}