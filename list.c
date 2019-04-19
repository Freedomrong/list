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

//    创建链表函数定义
PNode CreateList(void)
 {
    int len ;    //    用于定义链表长度
    int val ;    //    用于存放节点数值
    PNode PHead = (PNode)malloc(sizeof(Node));    //    创建分配一个头节点内存空间
    if (PHead == NULL)    //    判断是否分配成功
    {
        printf("Space allocation failed \n");
        exit(-1);
    }

    PNode PTail = PHead;    //    链表的末尾节点，初始指向头节点
    PTail->Next = NULL;    //    最后一个节点指针置为空
    printf("Please enter the number of nodes：");
    scanf("%d", &len);        //    输入节点个数
    for (int i = 0; i < len; i++) {

        PNode PNew = (PNode)malloc(sizeof(Node));    //    分配一个新节点
        if (PNew == NULL) {
            printf("Failed to assign new node\n");
            exit(-1);
        }
        printf("Please enter the data for the %d node：", i + 1);
        scanf("%d", &val);    //    输入链表节点的数据

        PNew->Element = val;    //    把数据赋值给节点数据域
        PTail->Next = PNew;    //    末尾节点指针指向下一个新节点
        PNew->Next = NULL;        //    新节点指针指向为空
        PTail = PNew;    //    将新节点复制给末尾节点        
    }
    printf("Create a linked list successfully\n");
    return PHead;    //    返回头节点
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

//定义链表遍历函数
void TraverseList(PNode List) {
    PNode P = List->Next;    //    首节点赋值给临时节点P
    printf("Traversing the value of the linked list");
    if (P == NULL)
        printf("The linked list is empty");
    while (P != NULL)        //当临时节点P不为尾节点时，输出当前节点的值
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

//定义删除整个链表函数
void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //定义指针P指向链表要删除的链表List的第一个点节点
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //临时Tmp指向要删除的节点的下个节点
        free(P);    //释放指针P指向的节点
        P = Tmp;    //重新赋值
    }

	    printf("Successfully deleted list！\n");
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
		printf("Memory allocation failed！");
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

/*
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
    current = L->next;  
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
    L->next = current;  
    return L;
}

	//    删除节点
	PNode Tmp = P->Next;    //    定义临时指针Tmp指向要删除的节点
	P->Next = Tmp->Next;    //    使要删除节点的前驱结点指向其后驱节点
	free(Tmp);    //    释放删除节点的内存空间，防止内存泄漏
	Tmp = NULL;    //    使q指向空指针，防止产生野指针
}

*/