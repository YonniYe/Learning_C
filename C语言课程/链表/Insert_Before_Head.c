struct Node *Insert_Before_Head(node *head, node *newp)
{
    newp->next = head;  //�½ڵ�ĺ��ָ��ԭ����ͷ���
    head = newp;    //�½ڵ�ĵ�ַ�ǵ�ǰ��ͷָ��
    return head;    //����ͷ���
}