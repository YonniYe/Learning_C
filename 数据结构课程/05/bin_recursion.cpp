// 非递归遍历二叉树

#include<stdio.h>
#include<stdlib.h>

typedef struct BinTreeNode {
	char data;
	int count;  // 标记入栈次数
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BinTreeNode;

#define M 100

// 自定义栈数据结构
typedef struct {
	BinTreeNode* elements[M];
	int top;  // 栈顶指针
}SeqStack;

// 将栈设置为空
void setStackNULL(SeqStack &s) {
	s.top = 0;
}

// 判断栈是否为空
bool isStackEmpty(SeqStack &s) {
	return s.top == 0;
}

// 入栈
void push(SeqStack &s, BinTreeNode* temp) {
	s.elements[s.top++] = temp;
}

// 出栈（出栈前需要判断）
BinTreeNode* pop(SeqStack &s) {
	return s.elements[--s.top];
}

// 从文本中读取二叉树
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

// 前序遍历
void preOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // 临时保存树根，避免影响后续
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			printf("%c", temp->data);
			push(s, temp);
			temp = temp->left;
		}
		// 前提即 temp=NULL，表示左边的元素已经全部入栈
		if (s.top != 0) {
			temp = pop(s);
			temp = temp->right; // 如果右边为空，就又满足了temp==NULL
		}
	}
	printf("\n");
}

// 中序遍历
void inOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // 临时保存树根，避免影响后续
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

// 后序遍历
// 对根节点而言，不止压一次栈，先左，后右，最后才是自己
// 引入 count 标记第二次入栈
void postOrderTravel(BinTreeNode* node) {
	SeqStack s;
	setStackNULL(s);
	BinTreeNode* temp = node;  // 临时保存树根，避免影响后续
	while (temp != NULL || s.top != 0) {
		while (temp != NULL) {
			temp->count = 1;
			push(s, temp);
			temp = temp->left;
		}
		// 左边走完了，访问右边
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
	puts("前序遍历结果为：");
	preOrderTravel(root);
	puts("中序遍历结果为：");
	inOrderTravel(root);
	puts("后序遍历结果为：");
	postOrderTravel(root);
	puts("释放二叉树内存空间");
	deleteNode(root);
	preOrderTravel(root);
	return 0;
}