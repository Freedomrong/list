#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"


//    ���������������
void TraverseList(PNode List) {
    PNode P = List->Next;    //    �׽ڵ㸳ֵ����ʱ�ڵ�P
    printf("���������ֵΪ��");
    if (P == NULL)
        printf("����Ϊ��");
    while (P != NULL)        //����ʱ�ڵ�P��Ϊβ�ڵ�ʱ�������ǰ�ڵ�ֵ 
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //����ָ��Pָ������Ҫɾ��������List�ĵ�һ����ڵ�
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //��ʱTmpָ��Ҫɾ���Ľڵ���¸��ڵ�
        free(P);    //�ͷ�ָ��Pָ��Ľڵ�
        P = Tmp;    //���¸�ֵ
    }
    printf("ɾ������ɹ���\n");
}

//     ����������뺯��
//    ������λ�õ�pos�ڵ�ǰ�����������val�Ľڵ�
void InsertList(PNode List, int pos, int val) {
	int position = 0;
	PNode P = List;    //    ����ڵ�pָ��ͷ�ڵ�
	//    Ѱ��pos�ڵ��ǰ�����
	while (P != NULL&&position<pos - 1)
	{
		P = P->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));    //    ����һ����ʱ�ڵ������洢Ҫ���������
	if (Tmp == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	//    ����ڵ�
	Tmp->Element = val;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}


//   ����ɾ������Ԫ�غ���
//    ɾ�������еĵ�pos�ڵ�
void DeleteList(PNode List, int pos) {
	int position = 0;
	PNode P = List;    //    ����һ��ָ��pָ������ͷ�ڵ�
	//    Ѱ��pos�ڵ�λ�õ�ǰ���ڵ�
	while (P != NULL&&position < pos - 1) {
		P = P->Next;
		++position;
	}

	//    ɾ���ڵ�
	PNode Tmp = P->Next;    //    ������ʱָ��Tmpָ��Ҫɾ���Ľڵ�
	P->Next = Tmp->Next;    //    ʹҪɾ���ڵ��ǰ�����ָ��������ڵ�
	free(Tmp);    //    �ͷ�ɾ���ڵ���ڴ�ռ䣬��ֹ�ڴ�й©
	Tmp = NULL;    //    ʹqָ���ָ�룬��ֹ����Ұָ��
}

//�����ѡ������#######################################################
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


// ������ת/����##################################################
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
