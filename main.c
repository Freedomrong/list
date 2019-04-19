#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "list.h"

int main() {
	
    PNode List = CreateList();    //    创建一个指针，使其指向新创建的链表的头指针    
    TraverseList(List);        //    遍历链表
    InsertList(List, 3, 100);    //    链表插入，在第三个位置插入数值100
    TraverseList(List);
    DeleteList(List, 3);    //    删除链表第三个节点
    TraverseList(List);
    DeleteTheList(List);    //    删除整个链表
    TraverseList(List);
    return 0;
}