#ifdef _LIST_H_
#define _LIST_H_

typedef int ElementType;        //    定义数据类型,可根据需要进行其他类型定义
                                //    链表节点的定义
typedef struct ListNode {
    ElementType  Element;        //    数据域，存放数据
    ListNode* Next;        //    指向下一个链表节点
}Node, *PNode;

InitList(PNode *L);
void CreateFromTail(PNode L);
PNode *amendElem(PNode * p,int add,int newElem);
void TraverseList(PNode List);
void DeleteTheList(PNode List);
void InsertList(PNode List, int pos, int val);
void DeleteList(PNode List, int pos);

#endif