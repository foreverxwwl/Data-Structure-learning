#include<stdio.h>
#include<malloc.h>

//定义结构体
typedef struct Node{
	int data;
	struct Node * next;
}Node, *LinkList;//一个结构体类型的Node，一个指向结构体类型的指针变量 LinkList

//初始化
InitList(LinkList * l)
{
	//分配头结点
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = NULL; //让头节点next域为空
}

//头插法建表，依次输入想要插入的值，以-1结束
void CreatFormHead(LinkList l)
{
	Node * s;
	int c;
	int flag = 1;
	while (flag)//循环标记
	{
		scanf("%d", &c);
		if (c != -1)
		{
			//建立一个新节点
			s = (Node*)malloc(sizeof(Node));
			//修改指针
			s->data = c;
			s->next = l->next;
			l->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}

//尾插法建表,与头插法类似，不过此方法建表为正序
void CreatFormTail(LinkList l)
{
	Node * s;
	//尾插需要有一个移动的指针，为了不丢失头结点则新定义一个指针r
	Node * r = l;
	int c;
	int flag = 1;
	while (flag)
	{
		scanf("%d", &c);
		if (c != -1)
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			r->next = s;
			r = r->next;
		}
		else
		{
			flag = 0;
		}
		r->next = NULL;
	}
}

//在单链表l的第i个元素前插入一个节点
void lnslist(LinkList l, int i, int idata)
{
	Node * pre, *s;
	int j = 0;
	pre = l;
	//首先判断插入位置是否合法
	if (i <= 0)
	{
		//插入位置小于1
		printf("查找序号不合法");
		return NULL;
	}
	//寻找插入位置
	while ((pre != NULL) && (j<i - 1))
	{
		pre = pre->next;
		j++;
	}
	if (pre == NULL)
	{
		//插入位置大于链表长度
		printf("查找序号不合法");
		return NULL;
	}
	s = (Node *)malloc(sizeof(Node));
	s->data = idata;
	s->next = pre->next;
	pre->next = s;
}

//删除第i个元素，并将该元素内容存入data中
void DeleteList(LinkList l, int i, int * data)
{
	Node * r = l;
	Node * p = l;
	int j = 0;
	if (i <= 0)
	{
		//删除位置小于1
		printf("查找序号不合法");
		return NULL;
	}
	//寻找删除位置
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		//删除位置大于链表长度
		printf("查找序号不合法");
		return NULL;
	}
	//修改指针删除
	r = p->next;
	p->next = r->next;
	* data = r->data;
	free(r);
}

//按数值key查找节点，将查找到的节点返回
Node * locate(LinkList l, int key)
{
	//定义一个可以移动的指针
	Node * r = l;
	while (r->data != key)
	{
		r = r->next;
		if (r == NULL)
		{
			//key值不存在链表中
			printf("查找不到相应值");
			return NULL;
		}
	}
	return r;
}
//按序号i(第i个)查找，将查找到的节点返回
Node * getNode(LinkList l, int i)
{
	Node * r = l;
	int j = 0;
	if (i <= 0)
	{
		//查找位置小于1
		printf("查找序号不合法");
		return NULL;
	}
	while (r != NULL || j <= i)
	{
		r = r->next;
		j++;
	}
	if (r == NULL)
	{
		//查找位置大于链表长度
		printf("查找值不合理");
		return NULL;
	}
	else
		return r;
}

//链表合并,将两个增有序的链表合成一个减有序的链表
LinkList MergeList(LinkList l1, LinkList l2)
{
	Node * s;
	Node * temp;
	//首先用其中一个链表头结点作为新链表头结点
	s = l1;
	l1 = l1->next;
	s->next = NULL;
	//定义一个临时节点，以便头插法建表时移动链表
	temp = l2;
	l2 = l2->next;
	free(temp);
	//l1，l2都指向待比较的节点
	while (l1 != NULL && l2 != NULL)
	{
		//选择两者中小的进行插入
		if (l1->data <= l2->data){
			//要先保留l1指针并移动，然后再修改指针
			temp = l1;
			l1 = l1->next;
			temp->next = s->next;
			s->next = temp;
		}
		else
		{
			temp = l2;
			l2 = l2->next;
			temp->next = s->next;
			s->next = temp;

		}
	}
	//当一个链表插入结束后，将另一个链表继续使用头插法逐一插入，
	//以保证建表顺序
	if (l1 == NULL)
	{
		while (l2 != NULL)
		{
			temp = l2;
			l2 = l2->next;
			temp->next = s->next;
			s->next = temp;
		}
	}
	else
	{
		while (l1 != NULL)
		{
			temp = l1;
			l1 = l1->next;
			temp->next = s->next;
			s->next = temp;
		}
	}
	return s;
}

//将两个增有序的链表合成一个增有序的链表
LinkList mergelinklist(LinkList la, LinkList lb)
{
	Node * r, *p, *s;
	LinkList lc;
	//与上一个插入类似，先建立头结点
	r = la->next;
	p = lb->next;
	lc = la;
	lc->next = NULL;
	s = lc;
	while (r->next != NULL || p->next != NULL)
	{
		//应为是尾插，本来就有移动临时节点，所以和标准尾插一样
		if (r->data <= p->data)
		{
			s->next = r;
			s = r;
			r = r->next;
		}
		else
		{
			s->next = p;
			s = p;
			p = p->next;
		}
	}
	//一方插入结束后，应为用尾插法，所以可以将另一方直接接到新节点后
	if (r->next != NULL)
		s->next = r;
	else
		s->next = p;
	free(lb);
	return(lc);
}

//链表复制,返回复制后链表
LinkList cloneList(LinkList l)
{
	Node * r = l->next;//定义一个指向原链表的移动指针
	Node * p;//定义一个指向新链表的移动指针
	LinkList s, l2;//s指向是新建立的节点，l2为新链表的头指针
	l2 = (Node *)malloc(sizeof(Node));//初始化l2链表
	l2->next = NULL;//一定要将尾节点指针域赋空，在以后移动指针判断操作才不会出现空指针异常
	p = l2;//将p指向头，方便尾插法建表
	while (r != NULL)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = r->data;//给新节点复制值
		r = r->next;//指向原链表下一个待复制位置
		s->next = p->next;//将新节点接入
		p->next = s;//将尾节点指针域赋值
		p = p->next;//p指向新最新节点
	}
	return l2;
}

//计算链表长度
int listlength(LinkList l)
{
	Node * p;
	int j = 0;
	p = l->next;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}
//链表输出
void PrintList(LinkList l)
{
	Node * r = l->next;
	while (r != NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
}

int main(void)
{
	LinkList l1;
	LinkList l2;
	LinkList s;
	int data = 0;
	InitList(&l1);
	InitList(&l2);
	printf("请输入第一个链表");
	CreatFormTail(l1);//尾插法建表1
	PrintList(l1);
	printf("请输入第二个链表");
	CreatFormHead(l2);//头差法建表2
	PrintList(l2);
	printf("\n");
	lnslist(l1, 2, 5);//在l1链表第2个位置插入5
	PrintList(l1);
	printf("\n");
	DeleteList(l2, 2, &data);//删除元素
	printf("%d", data);//输出删除元素
	printf("\n");
	PrintList(l2);
	printf("\n");
	s = locate(l2, 3);//查找值为3的节点
	printf("%d",s->data);
	printf("\n");
	s = MergeList(l1, l2);//两链表合并
	PrintList(s);
	s = cloneList(l1);//克隆l1
	PrintList(s);
	return 0;
}