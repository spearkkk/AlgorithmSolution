/**
* @file		stair_climbing.cpp
* @date		2016.09.04.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2579 #dynamic programming
*/
#include <stdio.h>
#include <algorithm>

int main() {
	int cnt;
	int stair[301];
	int score[301][2];

	// read input data
	scanf("%d", &cnt);
	fgetc(stdin);

	stair[0] = 0;
	for (int i = 1; i < cnt + 1; ++i) {
		scanf("%d", &stair[i]);
		fgetc(stdin);
	}

	// climbing
	// ù ��ܰ� �ι�° ����� ���� ó��
	// ���� �� �ܰ踶�� �ִ�� ���� �� �ִ� ���� �迭�� �����Ѵ�.
	// �÷��� 0�� ���� ���� ��ܿ��� �� ��� �ö�� ���̴�. ���� score[i - 1][0]�� ����ϸ� ���ǿ� �����ʴ´�.
	// �÷��� 1�� ���� �� ��� �������� 2ĭ �ö�� ���̹Ƿ� score[i - 2][0]�� score[i - 2][1]�� �� ����ؾ��Ѵ�.
	// ��, �� ��ܿ��� 2�� �� max ���� �������� ���� 2������ ���� ��� ������ �ִ´�.
	for (int i = 1; i < cnt + 1; ++i) {
		if (i == 1) {
			score[1][0] = stair[1];
			score[1][1] = 0;
			continue;
		}
		if (i == 2) {
			score[2][0] = stair[1] + stair[2];
			score[2][1] = stair[2];
			continue;
		}

		score[i][0] = score[i - 1][1] + stair[i];
		score[i][1] = std::max(score[i - 2][0], score[i - 2][1]) + stair[i];
	}
	printf("%d\n", std::max(score[cnt][0], score[cnt][1]));

	return 0;
}