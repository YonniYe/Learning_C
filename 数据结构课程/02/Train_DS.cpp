#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
	FILE* fp1, *fp2, *fp3;
	fopen_s(&fp1, "source.txt", "r");
	if (fp1 == NULL) {
		puts("Cannot open file source.txt");
		exit(0);
	}
	fopen_s(&fp2, "result1.txt", "w");
	if (fp2 == NULL) {
		puts("Cannot open file result1.txt");
		exit(0);
	}
	/* 以下使用数组写连续数据 */
	int nums[MAX]; // 数组
	int count = 0;
	while (fscanf_s(fp1, "%d", &nums[count]) != EOF)
		count++;
	for (int j = count - 1; j >= 0; j--){
		int data = nums[j];
		printf("%d ", data);
		fprintf(fp2, "%d ", data);
	}
	fclose(fp2);

	/* 以下使用malloc动态分配内存写连续数据 */
	rewind(fp1);
	int* p;
	count = 0; // 将count归零
	p = (int*)malloc(sizeof(int) * MAX);
	if (p == NULL) {  // 加入对malloc返回值的检查，去除C6011的报错
		printf("Allocate memory fail！\n");
	}
	else{
		while (fscanf_s(fp1, "%d", &p[count]) != EOF)
			count++;
	}
	fclose(fp1);
	fopen_s(&fp3, "result2.txt", "w");
	if (fp3 == NULL) {
		puts("Cannot open file result2.txt");
		exit(0);
	}
	for (int j = count - 1; j >= 0; j--) {
		int data = p[j];
		printf("%d ", data);
		fprintf(fp3, "%d ", data);
	}
	fclose(fp3);
	free(p);
	return 0;
}

