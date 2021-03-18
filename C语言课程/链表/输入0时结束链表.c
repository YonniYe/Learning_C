/*⑴ 创建一个链表，每个链表结点包括2个成员：1个整数和1个next指针，要求从键盘输入整数的值，当输入0表示数据输入结束；
⑵ 输出链表中每个结点的数据成员的值。
要求使用typedef机制给结点的结构体类型起一个简短的类型名字，并使用这个短类型名来定义变量。*/
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *next; //后继节点的地址
}LinkList;

void Output(LinkList *head)
{
    LinkList *p;
    p = head;
    while (p != NULL)
    {
        printf("%-4d", p->data);
        p = p->next;
    }
}

LinkList *create() //这里的*号意思是返回指针的函数,而返回的指针总是会指向首地址
{
    LinkList *head, *node, *end;
    head = (LinkList *)malloc(sizeof(LinkList));
    scanf("%d", &head->data);
    end = head;
    while (1)
    {
        node = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &node->data);
        end->next = node;
        end = node;
        if (node->data == 0)
        {                     //输入到0为止
            end->next = NULL; //当没有了新的node以后，就让end的next地址取NULL
            return head;
        }
    }
}

int main()
{
    printf("请不断输入链表中的元素（每输入一个敲一下回车）：\n");
    LinkList *head = create();
    printf("链表中所有元素的值为：\n");
    Output(head);
    free(head);
    return 0;
}