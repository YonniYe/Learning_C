struct Node *Insert_Before_Head(node *head, node *newp)
{
    newp->next = head;  //新节点的后继指向原来的头结点
    head = newp;    //新节点的地址是当前的头指针
    return head;    //返回头结点
}