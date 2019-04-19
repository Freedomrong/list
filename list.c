#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"


//链表的选择排序
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


/* 单链表反转/逆序 */
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
