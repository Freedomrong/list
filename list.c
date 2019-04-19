#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"

// 初始化单链表
InitList(PNode *L)
{
	* L = (PNode)malloc(sizeof(Node))
	(*L)->Next = NULL;

}
//尾插法建立单链表
void CreateFromTail(PNode L)
{
	Node *s,*r;
	char c;
	int flag = 1;
	r = L;
	while(flag)
	{
		c = getchar();
		if(c!='$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->Element = c;
			r->Next= s;
			r=s;
		}
		else
		{
			flag = 0;
			r->Next = NULL;
		}
	}
}

//更新结点的函数，newElem为新的数据域的值
PNode *amendElem(PNode * p,int add,int newElem)
{
	PNode * temp=p;
	temp=temp->Next;
	for (int i=1; i<add; i++)
	{
		temp=temp->Next;
	}
	temp->Element =newElem;
	return p;
}

//    ������������
void TraverseList(PNode List) {
    PNode P = List->Next;    //    �׽ڵ㸳ֵ����ʱ�ڵ�P
    printf("��������ֵΪ��");
    if (P == NULL)
        printf("���Ϊ��");
    while (P != NULL)        //����ʱ�ڵ�P��Ϊβ�ڵ�ʱ�����ǰ�ڵ�ֵ 
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //����ָ��Pָ�����Ҫɾ������List�ĵ�һ���ڵ�
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //��ʱTmpָ��Ҫɾ��Ľڵ���¸�ڵ�
        free(P);    //�ͷ�ָ��Pָ��Ľڵ�
        P = Tmp;    //���¸�ֵ
    }

	    printf("ɾ�����ɹ���\n");
}

//     ���������뺯��
//    �����λ�õ�pos�ڵ�ǰ��������val�Ľڵ�
void InsertList(PNode List, int pos, int val) {
	int position = 0;
	PNode P = List;    //    ����ڵ�pָ��ͷ�ڵ�
	//    Ѱ��pos�ڵ��ǰ����
=======
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

  PNode Tmp = (PNode)malloc(sizeof(Node));    //    ����һ����ʱ�ڵ�����洢Ҫ��������
	if (Tmp == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	//    ����ڵ�
=======
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


//   ����ɾ�����Ԫ�غ���
//    ɾ������еĵ�pos�ڵ�
void DeleteList(PNode List, int pos) {
	int position = 0;
	PNode P = List;    //    ����һ��ָ��pָ�����ͷ�ڵ�
	//    Ѱ��pos�ڵ�λ�õ�ǰ��ڵ�
=======
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

	//    ɾ��ڵ�
	PNode Tmp = P->Next;    //    ������ʱָ��Tmpָ��Ҫɾ��Ľڵ�
	P->Next = Tmp->Next;    //    ʹҪɾ��ڵ��ǰ����ָ�������ڵ�
	free(Tmp);    //    �ͷ�ɾ��ڵ���ڴ�ռ䣬��ֹ�ڴ�й©
	Tmp = NULL;    //    ʹqָ���ָ�룬��ֹ����Ұָ��
}

//����ѡ������#######################################################
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


// �����ת/����##################################################
Status ListReverse(LinkList L)
{
    LinkList current,pnext,prev;
    if(L == NULL || L->next == NULL)
        return L;
    current = L->next;  /* p1ָ�����ͷ�ڵ����һ��ڵ� */
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
    L->next = current;  /* �����ͷ�ڵ�ָ��p1 */
    return L;
}
=======
	//    删除节点
	PNode Tmp = P->Next;    //    定义临时指针Tmp指向要删除的节点
	P->Next = Tmp->Next;    //    使要删除节点的前驱结点指向其后驱节点
	free(Tmp);    //    释放删除节点的内存空间，防止内存泄漏
	Tmp = NULL;    //    使q指向空指针，防止产生野指针
}