/**
* @file		the_3n+1.cpp
* @date		2016.09.06.
* @author	spearkkk
* @brief	https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
*/
#include <stdio.h>

int get_cnt(int min, int max);

int main() {
	int check = 1;
	unsigned int min;
	unsigned int max;

	while (scanf("%d", &min) != EOF) {
		fgetc(stdin);
		scanf("%d", &max);
		fgetc(stdin);

		int cnt = 0;
		if (max < min) {
			cnt = get_cnt(max, min);
		}
		else {
			cnt = get_cnt(min, max);
		}

		printf("%d %d %d\n", min, max, cnt);
	}

	return 0;
}

int get_cnt(int min, int max) {
	int rslt = 0;

	for (int i = min; i < max + 1; ++i) {
		int input = i;
		int cnt = 0;

		while (input != 1) {
			if (input % 2 == 0) {
				input = input / 2;
			}
			else {
				input = input * 3 + 1;
			}
			++cnt;
		}
		if (rslt < cnt) {
			rslt = cnt;
		}
	}
	return rslt + 1;
}