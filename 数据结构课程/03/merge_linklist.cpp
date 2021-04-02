/* 
本题代码中的单链表均是含有`头结点`的类型
思路部分参考 http://data.biancheng.net/view/93.html
@叶宇轩 10190210
*/
#include<stdio.h>
#include<stdlib.h>
#define A 5
#define B 4
typedef struct Node {
	int data;
	struct Node* next;
}Linklist;

// 打印单链表中所有元素的data
void showLinkList(Linklist* head) {
	Linklist* p;
	p = head->next; // 头结点为空
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 先初始化，然后从数组创建单链表
Linklist* createFromArr(int source[], int n) {
	Linklist* head, * newp;
	head = (Linklist*)malloc(sizeof(Linklist));
	if (head == NULL) {
		printf("fail");
	}
	else {
		head->data = -1;
		head->next = NULL; // 头结点初始化为null
	}
	// 为保证递增顺序，倒序写入
	for (int i = n-1; i >= 0; i--) {
		newp = (Linklist*)malloc(sizeof(Linklist));
		if (newp == NULL) {
			printf("fail");
		}
		else {
			newp->data = source[i];
			newp->next = head->next;
			head->next = newp;
		}
	}
	return head;
}

// 对含有头结点的单链表进行就地逆置
void reverseLinkList(Linklist* head) {
	Linklist* p, * q;
	p = head->next;
	head->next = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
}

Linklist* Merge(Linklist* head1, Linklist* head2) {
	Linklist* p1, * p2, * p, * head;
	head = (Linklist*)malloc(sizeof(Linklist));
	if (head == NULL) {
		printf("fail");
	}
	else {
		head->data = -1;
		head->next = NULL; // 头结点初始化为null
	}
	p1 = head1->next;
	p2 = head2->next;
	// 下面的判断让head指向两个链表中`第一个元素`较小的那个
	if (p1->data < p2->data) {
		head->next = p1;
		p1 = p1->next;
	}
	else {
		head->next = p2;
		p2 = p2->next;
	}
	p = head->next;

	// 下面的判断依次比较p1、p2所指向元素的值，并把较小的添加到新的链表中
	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) {
			// p的后继节点取p1，
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
		else {
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
	}
	if (p1 != NULL) {
		p->next = p1;
	}
	else {
		p->next = p2;
	}
	return head;
}

int main() {
	int list_1[A] = { 2, 5, 6, 8, 11 };
	int list_2[B] = { 1, 5, 7, 10 };
	Linklist* head1 = createFromArr(list_1, A);
	Linklist* head2 = createFromArr(list_2, B);
	showLinkList(head1);
	showLinkList(head2);
	// 两链表合并
	Linklist* head_merge = Merge(head1, head2);
	showLinkList(head_merge);
	// 就地逆置合并后的链表
	reverseLinkList(head_merge);
	showLinkList(head_merge);
	// 释放节点！这老忘
	free(head1);
	free(head2);
	free(head_merge);
	return 0;
}