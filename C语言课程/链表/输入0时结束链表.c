/*�� ����һ������ÿ�����������2����Ա��1��������1��nextָ�룬Ҫ��Ӽ�������������ֵ��������0��ʾ�������������
�� ���������ÿ���������ݳ�Ա��ֵ��
Ҫ��ʹ��typedef���Ƹ����Ľṹ��������һ����̵��������֣���ʹ������������������������*/
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *next; //��̽ڵ�ĵ�ַ
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

LinkList *create() //�����*����˼�Ƿ���ָ��ĺ���,�����ص�ָ�����ǻ�ָ���׵�ַ
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
        {                     //���뵽0Ϊֹ
            end->next = NULL; //��û�����µ�node�Ժ󣬾���end��next��ַȡNULL
            return head;
        }
    }
}

int main()
{
    printf("�벻�����������е�Ԫ�أ�ÿ����һ����һ�»س�����\n");
    LinkList *head = create();
    printf("����������Ԫ�ص�ֵΪ��\n");
    Output(head);
    free(head);
    return 0;
}