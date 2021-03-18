/*编写一个程序，将递增的两个整数单链表合并成一个新的链表，合并后的链表依然保持递增有序，输出合并后的链表。*/
#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Node{
    int data;
    struct Node *next;  //后继节点的地址
}LinkList;

LinkList *create(int n)     //n是链表中元素个数
{
    LinkList *head, *node, *end;    //定义头节点，普通节点，尾部节点；
    head = (LinkList*)malloc(sizeof(LinkList));     //分配地址
    scanf("%d", &head->data);   //这里我直接给头节点赋值了。
    end = head;     //若是空链表则头尾节点一样
    for (int i = 0; i < n-1; i++)   //已经给头结点赋值过了，故只需给n-1个node赋值
    {
        node = (LinkList*)malloc(sizeof(LinkList));
        scanf("%d", &node->data);
        end->next = node;   //一开始end定义的是head。所以这里相当于是把head的下一个节点设立为了node
        end = node;     //然后把end也往后调一位，变成了最新的node
    }
    end->next = NULL;   //当没有了新的node以后，就让end的next地址取NULL
    return head;
}

void Output(LinkList *head)
{
    LinkList *p;
    p=head;
    while (p!=NULL){
        printf("%-4d",p->data);
        p=p->next;
    }
}

LinkList *Merge(LinkList *head1, LinkList *head2)
{
    LinkList *p1,*p2,*p,*head;
    head = (LinkList*)malloc(sizeof(LinkList));  
    p1=head1;
    p2=head2;
    if(p1->data < p2->data){    //这里的if-else让head指向两个链表中首元素较小的的那个链表
        head=p1;
        p1=p1->next;
    }
    else{
        head=p2;
        p2=p2->next;
    }

    p=head;
    while(p1!=NULL && p2!=NULL) //依次比较p1,p2所指向元素的值，把小的连接到新的链表中，并向后移动。直到p1,p2其中一个指向NULL。
    {
        if(p1->data <= p2->data){   //如果p1所指的数据较小，就让p(head)的后继节点地址取p1，同时p取到p1，p1往后移
            p->next=p1;
            p=p1;
            p1=p1->next;
        }
        else{
            p->next=p2; //p2同理
            p=p2;
            p2=p2->next;
        }
    }
    if(p1!=NULL)    //因为上面的while循环是p1、p2都不为NULL，所以还要再分类
        p->next=p1;
    else
        p->next=p2;
    return head;
}

int main()
{
    printf("请按照递增顺序输入第一个链表中的三个元素：\n");
    LinkList *head1 = create(N);
    printf("请按照递增顺序输入第二个链表中的三个元素：\n");
    LinkList *head2 = create(N);
    printf("初始化后的链表一、二分别为：\n");
    Output(head1);
    printf("\n");
    Output(head2);
    printf("\n");
    printf("两链表合并后的输出结果为：\n");
    LinkList *head = Merge(head1,head2);
    Output(head);
    free(head1);
    free(head2);
    free(head);
    return 0;
}