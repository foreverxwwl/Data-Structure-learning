#ifndef CORC___LINKPOINT_H
#define CORC___LINKPOINT_H

/*
* 双向链表相比于普通链表，最大的优势在于有一个指向前一个节点的指针
* 这样可以在操作中很方便的找到一个节点的前驱节点
* 同样的在双向链表中，也使用一个空余的节点作为头结点,在初始化时定义
*/

//双向链表结构体
//定义结构体类型Node，和结构体指针类型LinkList
typedef struct Node{
	int data;//数据域
	struct Node * piror;//指向前节点指针
	struct Node * next;//指向后节点指针
}Node, *LinkList;

//双向链表初始化，传入的是头指针l的地址
void initList(LinkList * l);
//建立新链表，输入要插入的内容，以-1结束
void creatFormTail(LinkList l);
//在循环链表l的第i个元素前插入一个节点
void lnslist(LinkList l, int i, int data);
//删除第i个元素，并将该元素内容存入data中
void deleteList(LinkList l, int i, int * data);
//链表复制,返回复制后链表
LinkList cloneList(LinkList l);
//链表输出
void printList(LinkList l);

#endif