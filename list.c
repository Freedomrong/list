#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"


//�����ѡ������
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


/* ������ת/���� */
Status ListReverse(LinkList L)
{
    LinkList current,pnext,prev;
    if(L == NULL || L->next == NULL)
        return L;
    current = L->next;  /* p1ָ������ͷ�ڵ����һ���ڵ� */
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
    L->next = current;  /* ������ͷ�ڵ�ָ��p1 */
    return L;
}
