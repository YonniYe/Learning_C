#include <stdio.h>

const int N = 8;
int queens[N] = { 0 };
int count = 0; // 种类

void print_queens() {
	// 输出当前八皇后的放置方式
	for (int row = 0; row < N; row++) {
		// 在皇后之前的位置打印“-”
		int col = 0;
		for (col = 0; col < queens[row]; col++) {
			printf("-");
		}

		printf("$");

		for (int col = queens[row] + 1; col < N; col++) {
			printf("-");
		}
		printf("\n");
	}
	printf("===========================\n");

}

bool check(int row, int col) {
	// 检查指定的某行、某列放置皇后是否会冲突

	// for 循环遍历之前的所有皇后的位置
	for (int r = 0; r < row; r++) {
		int c = queens[r];

		// 如果皇后在同一列，则冲突！
		if (col == c) {
			return false;
		}

		// 如果皇后在“左下-右上”对角线，则冲突！
		if ((row + col) == (r + c)) {
			return false;
		}

		// 如果皇后在“左下-右上”对角线，则冲突！
		if ((row - col) == (r - c)) {
			return false;
		}
	}
	return true;
}

void eightQueen(int row) {
	for (int col = 0; col < N; col++) {
		if (check(row, col)) {
		// 如果没有冲突
			queens[row] = col;

			// 如果摆到最后一行，就结束循环
			if (row == N - 1) {
				count++;  // 找到一个正确的放置方法
				print_queens();   // 输出打印
				queens[row] = 0; // 重置
				return;
			}

			// 否则，继续看下一行，递归执行函数
			eightQueen(row + 1);

			queens[row] = 0;
		}
	}
}

int main(int argc, char* argv[]) {

	eightQueen(0);
	printf("总共有 %d 种放置方式", count);
	return 0;
}