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
	// 仅需要插入值，而不需要插入地址
	if (S.top - S.base >= S.stacksize) {
		// 栈满则追加空间
		S.base = (SElemType*)realloc(S.base, sizeof(SElemType) * (S.stacksize + STACK_INCREMENT));
		if (!S.base)
			return -1;
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top++ = e; // ++的优先级高
	return 1;
}

Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return -1;
	e = *(--S.top);
	return 1;
}

// 去除字符串空格
void removeSpaces(char str[]) {
	char* p = str;
	int i = 0;
	while (*p != '\0') {
		// 如果指针指向空格，则不写入str[]，指针再往后移动
		if (*p != ' ') {
			str[i++]=*p; // 等价于：① str[i]=*p; ② i++;
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
	puts("After removing the space：");
	puts(str);

	int index = 0;
	// 使字符依次入栈
	while (str[index] != '\0') {
		Push(S, str[index]);
		index++;
	}

	int len = strlen(str);  // 获取去除空格后字符串的真实长度

	// 从栈依次弹出字符串的后半段，写入一个新字符数组
	for (int i = 0; i <= len / 2 - 1; i++) {
		char temp;
		Pop(S, temp);
		new_str[i] = temp;
	}
	
	/* 打印字符串，测试
	index = 0;
	while (new_str[index] != '\0') {
		printf_s("%c", new_str[index]);
		index++;
	}*/

	memset(str, 0, sizeof(str)); // 清空字符串str
	// 将栈底元素重新写入str
	for (int i = 0; i <= len / 2 - 1; i++) {
		str[i] = *S.base;
		S.base++;
	}

	// 如果后半段的内容等于原本字符串前半段，则为回文
	if (strcmp(new_str, str) == 0) {
		puts("This string IS a palindrome string!");
	}
	else
		puts("This string IS NOT a palindrome string!");
	return 0;
}