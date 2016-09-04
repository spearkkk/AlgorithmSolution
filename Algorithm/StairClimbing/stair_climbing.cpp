#include <stdio.h>

int climbing(int idx, int& cnt, char state, int score, int& total, int* stair);

int main() {
	int cnt;
	int *stair;

	scanf("%d", &cnt);
	fgetc(stdin);
	stair = new int[cnt];

	int total = 0;
	for (int i = 0; i < cnt; ++i) {
		scanf("%d", &stair[i]);
		total += stair[i];
		fgetc(stdin);
	} 

	int score1 = climbing(0, cnt, 'a', stair[0], total, stair);
	int score2 = climbing(1, cnt, 'a', stair[1], total, stair);
	printf("%d\n", score1 > score2 ? score1 : score2);

	return 0;
}

int climbing(int idx, int& cnt, char state, int score, int& total, int* stair) {
	if (idx == cnt - 1) {
		return score;
	}
	if (idx == cnt - 2) {
		if (state == 'b') {
			return -1;
		}
		else {
			return score + stair[idx + 1];
		}
	}

	if (state == 'a') {
		total = total - stair[idx + 1] - stair[idx + 2];

		if (idx == cnt - 3) {
			return score + stair[idx + 2];
		}
		int tmp1 = climbing(idx + 1, cnt, 'b', score + stair[idx + 1], total, stair);
		int tmp2 = climbing(idx + 2, cnt, 'a', score + stair[idx + 2], total, stair);
		return tmp1 > tmp2 ? tmp1 : tmp2;
	}
	else {
		total = total - stair[idx + 1] - stair[idx + 2];
		return climbing(idx + 2, cnt, 'a', score + stair[idx + 2], total, stair);
	}
}