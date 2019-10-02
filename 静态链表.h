#ifndef CORC___LINKPOINT_H
#define CORC___LINKPOINT_H

/*
* 1.静态链表中，应为没有指针使用，所以我们用一个结构体数组来存放节点，用cur来代替指针，存放下一个元素在结构体数组中的位置。
* 2.在建立链表时，我们把这个结构体数组看成两个链，一个是没有存放内容的备用链，一个是存放了内容的使用链，
* 同样的我们确定一个头结点data不存放数据，cur存放的是下一个可插入元素的节点位置，初始化为1，为备用链的头，
* 确定一个尾节点，data也不存放数据，cur存放的是第一个存放了数据的节点的位置，为使用链的头。
* 3.这样定义的好处是：其一，当链表中间有元素被删除时，备用链头cur值存放中间被删节点的位置，这样下次插入就可以直接在此插入。
* 所以删除节点时可以不移动其他元素，下次插入只需要在备用链依次取就好。
* 4.其二，用最后一个位置存放使用链的头，是防止当结构体数组中第一个节点被删去，会丢失头节点位置，通过这个保存则可以随意删除。
* 5.静态链表中存放的数据彼此之间是非线性不连续的，是通过cur代替指针将其联系起来。
* 6.优点：再插入和删除时候，只需要修改游标，不需要移动元素，从而改进了顺序存储结构中插入和删除操作需要移动大量元素的缺点。
* 7.缺点：没有解决连续存储分配带来的表长难以确定的问题；失去了顺序存储结构随机存取的特性。
*/

#define MAXSIZE 7
//定义结构
typedef struct{
	int data;//数据域
	int cur;//下一个节点的下标
}StaticList[MAXSIZE];

//初始化静态链表,主要任务是让每一个节点cur指向下一个节点
void InitList(StaticList l);
//在插入元素时，为带插入元素寻找一个空间下标
int Malloc(StaticList l);
//删除元素时，将其位置保存，方便下次插入
void Free(StaticList l, int k);
//求静态链表中元素个数，不包括头尾节点
int ListLength(StaticList L);
//静态链表中i位置插入一个元素
void lnsertList(StaticList L, int i, int data);
//删除第i个元素，将值放入data中
void DeleteList(StaticList L, int i, int *data);
//输出链表
void printList(StaticList L);

#endif