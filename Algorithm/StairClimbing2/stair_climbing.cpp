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
	// 첫 계단과 두번째 계단은 따로 처리
	// 이후 각 단계마다 최대로 가질 수 있는 값을 배열로 저장한다.
	// 컬럼이 0인 것은 이전 계단에서 한 계단 올라온 것이다. 따라서 score[i - 1][0]을 사용하면 조건에 맞지않는다.
	// 컬럼이 1인 것은 두 계단 이전에서 2칸 올라온 것이므로 score[i - 2][0]과 score[i - 2][1]를 다 고려해야한다.
	// 즉, 각 계단에서 2개 중 max 값을 저장하지 말고 2가지의 값을 모두 가지고 있는다.
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