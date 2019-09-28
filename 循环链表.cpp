#include<stdio.h>
#include<stdlib.h>

//ѭ������
typedef struct Node{
	int data;
	struct Node * next;
}Node, *LinkList;

//��ʼ��
void InitList(LinkList * l)
{
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = *l;//��β�ڵ��ָ����ָ��ͷ���
	(*l)->data = NULL;//��ͷ����Data��Ϊ�գ��������ͷ���������ڵ�
}

//��������β�巨����������
void creatList(LinkList l)
{
	int data;
	Node * s;//����һ���½��ڵ�
	Node * r = l;//����һ���ƶ��ڵ�
	while (true)
	{
		scanf("%d", &data);
		if (data != -1)
		{
			s = (Node *)malloc(sizeof(Node));
			s->data = data;
			r->next = s; //�޸�ָ��
			s->next = l;
			r = r->next;
		}
		else{
			break;
		}
	}
}

//�����½ڵ㣬��iλ�ò���ֵΪData�Ľڵ�
void InsertNode(LinkList l, int i, int data)
{
	Node * r = l;
	Node * p = l;
	Node * s;
	int j = 0;
	if (i <= 0)//�жϲ���λ��
	{
		printf("����λ��С��1");
		return;
	}
	//�ƶ�p�ڵ㣬p�ڵ��Ǵ�ɾ���ڵ��ǰһ���ڵ�
	while (p->next->next != l && j != i - 1)
	{
		p = p->next;
		j++;
	}
	r = p->next;
	if (r == l)
	{
		printf("�Ҳ���������λ��");
		return;
	}
	//�½��ڵ㲢����
	s = (Node *)malloc(sizeof(Node));
	s->data = data;
	p->next = s;
	s->next = r;
}

//ɾ���ڵ㣬ɾ����i���ڵ�
void deleteList(LinkList l, int i)
{
	Node * r = l;
	Node * p = l;
	int j = 0;
	if (i <= 0)
	{
		printf("ɾ��λ��С��1");
		return ;
	}
	//�ƶ�p�ڵ㣬p�ڵ��Ǵ�ɾ���ڵ��ǰһ���ڵ�
	while (p->next->next != l && j != i - 1)
	{
		p = p->next;
		j++;
	}
	r = p->next;
	if (r == l)
	{
	    printf("�Ҳ�����ɾ���ڵ�");
		return;
	}
	//ֱ��ɾ������Ӱ��ͷ����βָ��
	p->next = r->next;
	free(r);
}

//���ҽڵ㣬���ҵ�i���ڵ�
Node * gitNode(LinkList l, int i)
{
	Node * r = l;
	int j = 0;
	if (i <= 0)
	{
		printf("����λ��С��1");
		return NULL;
	}
	while (r->next != l && j != i)
	{
		r = r->next;
		j++;
	}
	if (r == l)
	{
		printf("�Ҳ��������ҽڵ�");
		return NULL;
	}
	return r;
}

//�������
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
	InitList(&l);//��ʼ������
	creatList(l);//����������
	printList(l);
	InsertNode(l, 3, 5);//��3λ�ò���ֵ5
	printList(l);
	deleteList(l, 2);//ɾ��2�ڵ�
	printList(l);
	s = gitNode(l, 4);//����4�ڵ�
	printf("%d", s->data);
	return 0;
}