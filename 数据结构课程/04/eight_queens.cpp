#include <stdio.h>

const int N = 8;
int queens[N] = { 0 };
int count = 0; // ����

void print_queens() {
	// �����ǰ�˻ʺ�ķ��÷�ʽ
	for (int row = 0; row < N; row++) {
		// �ڻʺ�֮ǰ��λ�ô�ӡ��-��
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
	// ���ָ����ĳ�С�ĳ�з��ûʺ��Ƿ���ͻ

	// for ѭ������֮ǰ�����лʺ��λ��
	for (int r = 0; r < row; r++) {
		int c = queens[r];

		// ����ʺ���ͬһ�У����ͻ��
		if (col == c) {
			return false;
		}

		// ����ʺ��ڡ�����-���ϡ��Խ��ߣ����ͻ��
		if ((row + col) == (r + c)) {
			return false;
		}

		// ����ʺ��ڡ�����-���ϡ��Խ��ߣ����ͻ��
		if ((row - col) == (r - c)) {
			return false;
		}
	}
	return true;
}

void eightQueen(int row) {
	for (int col = 0; col < N; col++) {
		if (check(row, col)) {
		// ���û�г�ͻ
			queens[row] = col;

			// ����ڵ����һ�У��ͽ���ѭ��
			if (row == N - 1) {
				count++;  // �ҵ�һ����ȷ�ķ��÷���
				print_queens();   // �����ӡ
				queens[row] = 0; // ����
				return;
			}

			// ���򣬼�������һ�У��ݹ�ִ�к���
			eightQueen(row + 1);

			queens[row] = 0;
		}
	}
}

int main(int argc, char* argv[]) {

	eightQueen(0);
	printf("�ܹ��� %d �ַ��÷�ʽ", count);
	return 0;
}