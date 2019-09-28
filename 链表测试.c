#include<stdio.h>
#include<malloc.h>

//����ṹ��
typedef struct Node{
	int data;
	struct Node * next;
}Node, *LinkList;//һ���ṹ�����͵�Node��һ��ָ��ṹ�����͵�ָ����� LinkList

//��ʼ��
InitList(LinkList * l)
{
	//����ͷ���
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = NULL; //��ͷ�ڵ�next��Ϊ��
}

//ͷ�巨��������������Ҫ�����ֵ����-1����
void CreatFormHead(LinkList l)
{
	Node * s;
	int c;
	int flag = 1;
	while (flag)//ѭ�����
	{
		scanf("%d", &c);
		if (c != -1)
		{
			//����һ���½ڵ�
			s = (Node*)malloc(sizeof(Node));
			//�޸�ָ��
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

//β�巨����,��ͷ�巨���ƣ������˷�������Ϊ����
void CreatFormTail(LinkList l)
{
	Node * s;
	//β����Ҫ��һ���ƶ���ָ�룬Ϊ�˲���ʧͷ������¶���һ��ָ��r
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

//�ڵ�����l�ĵ�i��Ԫ��ǰ����һ���ڵ�
void lnslist(LinkList l, int i, int idata)
{
	Node * pre, *s;
	int j = 0;
	pre = l;
	//�����жϲ���λ���Ƿ�Ϸ�
	if (i <= 0)
	{
		//����λ��С��1
		printf("������Ų��Ϸ�");
		return NULL;
	}
	//Ѱ�Ҳ���λ��
	while ((pre != NULL) && (j<i - 1))
	{
		pre = pre->next;
		j++;
	}
	if (pre == NULL)
	{
		//����λ�ô���������
		printf("������Ų��Ϸ�");
		return NULL;
	}
	s = (Node *)malloc(sizeof(Node));
	s->data = idata;
	s->next = pre->next;
	pre->next = s;
}

//ɾ����i��Ԫ�أ�������Ԫ�����ݴ���data��
void DeleteList(LinkList l, int i, int * data)
{
	Node * r = l;
	Node * p = l;
	int j = 0;
	if (i <= 0)
	{
		//ɾ��λ��С��1
		printf("������Ų��Ϸ�");
		return NULL;
	}
	//Ѱ��ɾ��λ��
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		//ɾ��λ�ô���������
		printf("������Ų��Ϸ�");
		return NULL;
	}
	//�޸�ָ��ɾ��
	r = p->next;
	p->next = r->next;
	* data = r->data;
	free(r);
}

//����ֵkey���ҽڵ㣬�����ҵ��Ľڵ㷵��
Node * locate(LinkList l, int key)
{
	//����һ�������ƶ���ָ��
	Node * r = l;
	while (r->data != key)
	{
		r = r->next;
		if (r == NULL)
		{
			//keyֵ������������
			printf("���Ҳ�����Ӧֵ");
			return NULL;
		}
	}
	return r;
}
//�����i(��i��)���ң������ҵ��Ľڵ㷵��
Node * getNode(LinkList l, int i)
{
	Node * r = l;
	int j = 0;
	if (i <= 0)
	{
		//����λ��С��1
		printf("������Ų��Ϸ�");
		return NULL;
	}
	while (r != NULL || j <= i)
	{
		r = r->next;
		j++;
	}
	if (r == NULL)
	{
		//����λ�ô���������
		printf("����ֵ������");
		return NULL;
	}
	else
		return r;
}

//����ϲ�,�����������������ϳ�һ�������������
LinkList MergeList(LinkList l1, LinkList l2)
{
	Node * s;
	Node * temp;
	//����������һ������ͷ�����Ϊ������ͷ���
	s = l1;
	l1 = l1->next;
	s->next = NULL;
	//����һ����ʱ�ڵ㣬�Ա�ͷ�巨����ʱ�ƶ�����
	temp = l2;
	l2 = l2->next;
	free(temp);
	//l1��l2��ָ����ȽϵĽڵ�
	while (l1 != NULL && l2 != NULL)
	{
		//ѡ��������С�Ľ��в���
		if (l1->data <= l2->data){
			//Ҫ�ȱ���l1ָ�벢�ƶ���Ȼ�����޸�ָ��
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
	//��һ�������������󣬽���һ���������ʹ��ͷ�巨��һ���룬
	//�Ա�֤����˳��
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

//�����������������ϳ�һ�������������
LinkList mergelinklist(LinkList la, LinkList lb)
{
	Node * r, *p, *s;
	LinkList lc;
	//����һ���������ƣ��Ƚ���ͷ���
	r = la->next;
	p = lb->next;
	lc = la;
	lc->next = NULL;
	s = lc;
	while (r->next != NULL || p->next != NULL)
	{
		//ӦΪ��β�壬���������ƶ���ʱ�ڵ㣬���Ժͱ�׼β��һ��
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
	//һ�����������ӦΪ��β�巨�����Կ��Խ���һ��ֱ�ӽӵ��½ڵ��
	if (r->next != NULL)
		s->next = r;
	else
		s->next = p;
	free(lb);
	return(lc);
}

//����������
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
//�������
void PrintList(LinkList l)
{
	Node * r = l->next;
	while (r->next != NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
	printf("%d", r->data);
}

int main(void)
{
	LinkList l1;
	LinkList l2;
	LinkList s;
	int data = 0;
	InitList(&l1);
	InitList(&l2);
	printf("�������һ������");
	CreatFormTail(l1);//β�巨����1
	PrintList(l1);
	printf("������ڶ�������");
	CreatFormHead(l2);//ͷ�����2
	PrintList(l2);
	printf("\n");
	lnslist(l1, 2, 5);//��l1�����2��λ�ò���5
	PrintList(l1);
	printf("\n");
	DeleteList(l2, 2, &data);//ɾ��Ԫ��
	printf("%d", data);//���ɾ��Ԫ��
	printf("\n");
	PrintList(l2);
	printf("\n");
	s = locate(l2, 3);//����ֵΪ3�Ľڵ�
	printf("%d",s->data);
	printf("\n");
	s = MergeList(l1, l2);//������ϲ�
	PrintList(s);
	return 0;
}