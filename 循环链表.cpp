#include<stdio.h>
#include<stdlib.h>

/*定义循环链表结构
* 其中结构体变量Node 用来定义链表节点
* 结构体指针LinkList 用来定义头结点
*/
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
		else{//判断当输入值为-1时停止输入
			break;
		}
	}
}

//在i位置插入值为Data的节点
void InsertNode(LinkList l, int i, int data)
{
	Node * r = l;//查找指向待插入位置
	Node * p = l;//指向待插入节点前的节点
	Node * s;//指向新建的节点
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
	if (r == l)//插入位置大于链表长度
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

//删除第i个节点
void deleteList(LinkList l, int i)
{
	Node * r = l;//查找指向待删除节点
	Node * p = l;//指向待节点节点前的节点
	int j = 0;
	if (i <= 0)//判断删除位置
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
	if (r == l)//删除位置大于链表长度
	{
	    printf("找不到待删除节点");
		return;
	}
	//应为有头结点，位置为0，不在删除范围之内所以可以直接删除，
	//不会影响头结点和尾指针
	p->next = r->next;
	free(r);
}

//查找节点，查找第i个节点
Node * gitNode(LinkList l, int i)
{
	Node * r = l;//指向待查找节点
	int j = 0;
	if (i <= 0)//判断插入位置
	{
		printf("查找位置小于1");
		return NULL;
	}
	while (r->next != l && j != i)
	{
		r = r->next;
		j++;
	}
	if (r == l)//插入位置大于链表长度
	{
		printf("找不到待查找节点");
		return NULL;
	}
	return r;//将查找到了节点返回
}

/*输出链表
* 应为是循环链表，所以不用担心丢失头结点，
* 且在定义头结点时将其data域赋值为NULL做了标记
* 所以在循环时可以直接循环头指针l，
*/
void printList(LinkList l)
{
	l = l->next;//直接开始移动l指针
	while (l->data != NULL)//判断是否循环一圈回到头结点
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