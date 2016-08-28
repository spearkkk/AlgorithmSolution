/**
* @file		rgb_distance.cpp
* @date		2016.08.29.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1149 #dynamic programming
*/
#include <stdio.h>
#include <limits.h>

int drawing(int i, int j, int cnt, unsigned int **data, unsigned int weight);

int main() {
	int cnt;
	unsigned int **data;

	scanf("%d", &cnt);
	data = new unsigned int*[cnt];
	
	for (int i = 0; i < cnt; ++i) {
		data[i] = new unsigned int[3];
		for (int j = 0; j < 3; ++j) {
			scanf("%u", &data[i][j]);
			fgetc(stdin);
		}
	}

	unsigned int rslt[3];
	rslt[0] = drawing(0, 0, cnt, data, 0);
	rslt[1] = drawing(0, 1, cnt, data, 0);
	rslt[2] = drawing(0, 2, cnt, data, 0);
	if (rslt[0] < rslt[1]) {
		if (rslt[0] < rslt[2]) {
			printf("%u\n", rslt[0]);
		}
		else {
			printf("%u\n", rslt[2]);
		}
	}
	else {
		if (rslt[1] < rslt[2]) {
			printf("%u\n", rslt[1]);
		}
		else {
			printf("%u\n", rslt[2]);
		}
	}

	return 0;
}

int drawing(int row, int col, int cnt, unsigned int **data, unsigned int weight) {
	if (row == cnt) {	
		return weight;
	}
	unsigned int min = UINT_MAX;

	for (int i = 0; i < 3; ++i) {
		if (i == col) {
			continue;
		}
		unsigned int tmp = drawing(row + 1, i, cnt, data, data[row][col] + weight);
		if (min > tmp) {
			min = tmp;
		}
	}
	return min;
}
