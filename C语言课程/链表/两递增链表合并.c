/*��дһ�����򣬽���������������������ϲ���һ���µ������ϲ����������Ȼ���ֵ�����������ϲ��������*/
#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Node{
    int data;
    struct Node *next;  //��̽ڵ�ĵ�ַ
}LinkList;

LinkList *create(int n)     //n��������Ԫ�ظ���
{
    LinkList *head, *node, *end;    //����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
    head = (LinkList*)malloc(sizeof(LinkList));     //�����ַ
    scanf("%d", &head->data);   //������ֱ�Ӹ�ͷ�ڵ㸳ֵ�ˡ�
    end = head;     //���ǿ�������ͷβ�ڵ�һ��
    for (int i = 0; i < n-1; i++)   //�Ѿ���ͷ��㸳ֵ���ˣ���ֻ���n-1��node��ֵ
    {
        node = (LinkList*)malloc(sizeof(LinkList));
        scanf("%d", &node->data);
        end->next = node;   //һ��ʼend�������head�����������൱���ǰ�head����һ���ڵ�����Ϊ��node
        end = node;     //Ȼ���endҲ�����һλ����������µ�node
    }
    end->next = NULL;   //��û�����µ�node�Ժ󣬾���end��next��ַȡNULL
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
    if(p1->data < p2->data){    //�����if-else��headָ��������������Ԫ�ؽ�С�ĵ��Ǹ�����
        head=p1;
        p1=p1->next;
    }
    else{
        head=p2;
        p2=p2->next;
    }

    p=head;
    while(p1!=NULL && p2!=NULL) //���αȽ�p1,p2��ָ��Ԫ�ص�ֵ����С�����ӵ��µ������У�������ƶ���ֱ��p1,p2����һ��ָ��NULL��
    {
        if(p1->data <= p2->data){   //���p1��ָ�����ݽ�С������p(head)�ĺ�̽ڵ��ַȡp1��ͬʱpȡ��p1��p1������
            p->next=p1;
            p=p1;
            p1=p1->next;
        }
        else{
            p->next=p2; //p2ͬ��
            p=p2;
            p2=p2->next;
        }
    }
    if(p1!=NULL)    //��Ϊ�����whileѭ����p1��p2����ΪNULL�����Ի�Ҫ�ٷ���
        p->next=p1;
    else
        p->next=p2;
    return head;
}

int main()
{
    printf("�밴�յ���˳�������һ�������е�����Ԫ�أ�\n");
    LinkList *head1 = create(N);
    printf("�밴�յ���˳������ڶ��������е�����Ԫ�أ�\n");
    LinkList *head2 = create(N);
    printf("��ʼ���������һ�����ֱ�Ϊ��\n");
    Output(head1);
    printf("\n");
    Output(head2);
    printf("\n");
    printf("������ϲ����������Ϊ��\n");
    LinkList *head = Merge(head1,head2);
    Output(head);
    free(head1);
    free(head2);
    free(head);
    return 0;
}