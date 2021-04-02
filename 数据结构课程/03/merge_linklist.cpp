/* 
��������еĵ�������Ǻ���`ͷ���`������
˼·���ֲο� http://data.biancheng.net/view/93.html
@Ҷ���� 10190210
*/
#include<stdio.h>
#include<stdlib.h>
#define A 5
#define B 4
typedef struct Node {
	int data;
	struct Node* next;
}Linklist;

// ��ӡ������������Ԫ�ص�data
void showLinkList(Linklist* head) {
	Linklist* p;
	p = head->next; // ͷ���Ϊ��
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// �ȳ�ʼ����Ȼ������鴴��������
Linklist* createFromArr(int source[], int n) {
	Linklist* head, * newp;
	head = (Linklist*)malloc(sizeof(Linklist));
	if (head == NULL) {
		printf("fail");
	}
	else {
		head->data = -1;
		head->next = NULL; // ͷ����ʼ��Ϊnull
	}
	// Ϊ��֤����˳�򣬵���д��
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

// �Ժ���ͷ���ĵ�������о͵�����
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
		head->next = NULL; // ͷ����ʼ��Ϊnull
	}
	p1 = head1->next;
	p2 = head2->next;
	// ������ж���headָ������������`��һ��Ԫ��`��С���Ǹ�
	if (p1->data < p2->data) {
		head->next = p1;
		p1 = p1->next;
	}
	else {
		head->next = p2;
		p2 = p2->next;
	}
	p = head->next;

	// ������ж����αȽ�p1��p2��ָ��Ԫ�ص�ֵ�����ѽ�С����ӵ��µ�������
	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) {
			// p�ĺ�̽ڵ�ȡp1��
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
	// ������ϲ�
	Linklist* head_merge = Merge(head1, head2);
	showLinkList(head_merge);
	// �͵����úϲ��������
	reverseLinkList(head_merge);
	showLinkList(head_merge);
	// �ͷŽڵ㣡������
	free(head1);
	free(head2);
	free(head_merge);
	return 0;
}