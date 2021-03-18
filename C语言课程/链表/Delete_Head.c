#include<stdlib.h>
#include<stdio.h>
struct Node *Delete_Head(struct Node head);
{
    struct Node *p;
    if (head==NULL)
        return NULL;
    p=head;     //p指向头结点
    head=head->next;    //头指针指向头结点的下一个节点
    free(p);    //释放头结点，从而删除链表的头结点
    return head;
}
