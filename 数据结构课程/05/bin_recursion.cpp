// �ǵݹ����������

#include<stdio.h>
#include<stdlib.h>

typedef struct BinTreeNode {
	char data;
	int count;  // �����ջ����
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BinTreeNode;

#define M 100

// �Զ���ջ���ݽṹ
typedef struct {
	BinTreeNode* elements[M];
	int top;  // ջ��ָ��
}SeqStack;

// ��ջ����Ϊ��
void setStackNULL(SeqStack &s) {
	s.top = 0;
}

// �ж�ջ�Ƿ�Ϊ��
bool isStackEmpty(SeqStack &s) {
	return s.top == 0;
}

// ��ջ
void push(SeqStack &s, BinTreeNode* temp) {
	s.elements[s.top++] = temp;
}

// ��ջ����ջǰ��Ҫ�жϣ�
BinTreeNode* pop(SeqStack &s) {
	return s.elements[--s.top];
}

// ���ı��ж�ȡ������
void createBinTree(FILE* fp, BinTreeNode*& node) {
	char ch;
	if ((ch = fgetc(fp)) == '#')
		node = NULL;
	else {
		node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		node->data = ch;
	
		createBinTree(fp, node->left);
		createBinTree(fp, node->right);
	}
}

// ǰ�����
void preOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // ��ʱ��������������Ӱ�����
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			printf("%c", temp->data);
			push(s, temp);
			temp = temp->left;
		}
		// ǰ�ἴ temp=NULL����ʾ��ߵ�Ԫ���Ѿ�ȫ����ջ
		if (s.top != 0) {
			temp = pop(s);
			temp = temp->right; // ����ұ�Ϊ�գ�����������temp==NULL
		}
	}
	printf("\n");
}

// �������
void inOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // ��ʱ��������������Ӱ�����
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			push(s, temp);
			temp = temp->left;
		}
		if (s.top != 0) {
			temp = pop(s);
			printf("%c", temp->data);
			temp = temp->right;
		}
	}
	printf("\n");
}

// �������
// �Ը��ڵ���ԣ���ֹѹһ��ջ�����󣬺��ң��������Լ�
// ���� count ��ǵڶ�����ջ
void postOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // ��ʱ��������������Ӱ�����
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			temp->count = 1;
			push(s, temp);
			temp = temp->left;
		}
		// ��������ˣ������ұ�
		if (s.top != 0) {
			temp = pop(s);
			if (temp->count == 1) {
				temp->count += 1;
				push(s, temp);
				temp = temp->right;
			}
			else if (temp->count == 2) {
				printf("%c", temp->data);
				temp = NULL;
			}
		}
	}
	printf("\n");
}

void deleteNode(BinTreeNode *root) {
	if (root != NULL) {
		deleteNode(root->left);
		deleteNode(root->right);
		delete(root);
	}
}

int main() {
	FILE* fp;
	fopen_s(&fp, "BinTree.txt", "r");
	if (fp == NULL) {
		puts("Cannot read BinTree.txt");
		return -1;
	}
	BinTreeNode* root = NULL;
	createBinTree(fp, root);
	fclose(fp);
	if (root == NULL) {
		puts("BinTree is empty!");
		return -1;
	}
	puts("ǰ��������Ϊ��");
	preOrderTravel(root);
	puts("����������Ϊ��");
	inOrderTravel(root);
	puts("����������Ϊ��");
	postOrderTravel(root);
	puts("�ͷŶ������ڴ�ռ�");
	deleteNode(root);
	preOrderTravel(root);
	return 0;
}