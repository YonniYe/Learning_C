#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SElemType char
#define Status int
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status initStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		return -1;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}

Status Push(SqStack& S, SElemType e) {
	// ����Ҫ����ֵ��������Ҫ�����ַ
	if (S.top - S.base >= S.stacksize) {
		// ջ����׷�ӿռ�
		S.base = (SElemType*)realloc(S.base, sizeof(SElemType) * (S.stacksize + STACK_INCREMENT));
		if (!S.base)
			return -1;
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e; // ++�����ȼ���
	return 1;
}

Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return -1;
	e = *(--S.top);
	return 1;
}

// ȥ���ַ����ո�
void removeSpaces(char str[]) {
	char* p = str;
	int i = 0;
	while (*p != '\0') {
		// ���ָ��ָ��ո���д��str[]��ָ���������ƶ�
		if (*p != ' ') {
			str[i++]=*p; // �ȼ��ڣ��� str[i]=*p; �� i++;
		}
		p++;
	}
	str[i] = '\0';
}

int main() {
	SqStack S;
	initStack(S);
	char str[20], new_str[20]="";
	puts("Please input a string:");
	gets_s(str);
	removeSpaces(str);
	puts("After removing the space��");
	puts(str);

	int index = 0;
	// ʹ�ַ�������ջ
	while (str[index] != '\0') {
		Push(S, str[index]);
		index++;
	}

	int len = strlen(str);  // ��ȡȥ���ո���ַ�������ʵ����

	// ��ջ���ε����ַ����ĺ��Σ�д��һ�����ַ�����
	for (int i = 0; i <= len / 2 - 1; i++) {
		char temp;
		Pop(S, temp);
		new_str[i] = temp;
	}
	
	/* ��ӡ�ַ���������
	index = 0;
	while (new_str[index] != '\0') {
		printf_s("%c", new_str[index]);
		index++;
	}*/

	memset(str, 0, sizeof(str)); // ����ַ���str
	// ��ջ��Ԫ������д��str
	for (int i = 0; i <= len / 2 - 1; i++) {
		str[i] = *S.base;
		S.base++;
	}

	// ������ε����ݵ���ԭ���ַ���ǰ��Σ���Ϊ����
	if (strcmp(new_str, str) == 0) {
		puts("This string IS a palindrome string!");
	}
	else
		puts("This string IS NOT a palindrome string!");
	return 0;
}