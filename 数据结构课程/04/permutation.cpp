#include<stdio.h>

const int maxn = 10;
int n;
int P[maxn];
int flag[maxn] = { false };

void generateP(int index) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", P[i]);
		}
		printf("\n");
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (flag[x] == false) { // �ж�x�Ƿ��������
			P[index] = x;
			flag[x] = true;
			generateP(index + 1);  // �ݹ��׵ݹ�
			flag[x] = false;  // ��ԭ
		}
	}
}
int main() {
	n = 4;
	generateP(1);
	return 0;
}