#include<stdlib.h>
#include<stdio.h>
struct Node *Delete_Head(struct Node head);
{
    struct Node *p;
    if (head==NULL)
        return NULL;
    p=head;     //pָ��ͷ���
    head=head->next;    //ͷָ��ָ��ͷ������һ���ڵ�
    free(p);    //�ͷ�ͷ��㣬�Ӷ�ɾ�������ͷ���
    return head;
}
