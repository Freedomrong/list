#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"


//    定义链表遍历函数
void TraverseList(PNode List) {
    PNode P = List->Next;    //    首节点赋值给临时节点P
    printf("遍历链表的值为：");
    if (P == NULL)
        printf("链表为空");
    while (P != NULL)        //当临时节点P不为尾节点时，输出当前节点值 
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //定义指针P指向链表要删除的链表List的第一个点节点
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //临时Tmp指向要删除的节点的下个节点
        free(P);    //释放指针P指向的节点
        P = Tmp;    //重新赋值
    }
    printf("删除链表成功！\n");
}

//     定义链表插入函数
//    在链表位置第pos节点前插入包含数据val的节点
void InsertList(PNode List, int pos, int val) {
	int position = 0;
	PNode P = List;    //    定义节点p指向头节点
	//    寻找pos节点的前驱结点
	while (P != NULL&&position<pos - 1)
	{
		P = P->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));    //    分配一个临时节点用来存储要插入的数据
	if (Tmp == NULL)
	{
		printf("内存分配失败！");
		exit(-1);
	}
	//    插入节点
	Tmp->Element = val;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}


//   定义删除链表元素函数
//    删除链表中的第pos节点
void DeleteList(PNode List, int pos) {
	int position = 0;
	PNode P = List;    //    定义一个指针p指向链表头节点
	//    寻找pos节点位置的前驱节点
	while (P != NULL&&position < pos - 1) {
		P = P->Next;
		++position;
	}

	//    删除节点
	PNode Tmp = P->Next;    //    定义临时指针Tmp指向要删除的节点
	P->Next = Tmp->Next;    //    使要删除节点的前驱结点指向其后驱节点
	free(Tmp);    //    释放删除节点的内存空间，防止内存泄漏
	Tmp = NULL;    //    使q指向空指针，防止产生野指针
}

//链表的选择排序#######################################################
bool Sort_List(Node* head)
{
    int t = 0;
    int size = Size_List(head);
   
   for (Node* temp = head->next; temp != NULL; temp = temp->next)
   {
        for (Node* p = temp; p != NULL; p = p->next)
		{
            if (temp->data > p->data)
			{
                t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
        }
    } 
}


// 单链表反转/逆序##################################################
Status ListReverse(LinkList L)
{
    LinkList current,pnext,prev;
    if(L == NULL || L->next == NULL)
        return L;
    current = L->next;  /* p1指向链表头节点的下一个节点 */
    pnext = current->next;
    current->next = NULL;
    while(pnext)
    {
        prev = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = prev;
    }
    //printf("current = %d,next = %d \n",current->data,current->next->data);
    L->next = current;  /* 将链表头节点指向p1 */
    return L;
}
