/**
* @file		wine_taste.cpp
* @date		2016.09.13.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2156, #dynamic programming
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cnt;
	vector<int> wines(10001, 0);
	vector<vector<int>> total(10001, vector<int>(3, 0));

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 1; i < cnt + 1; ++i) {
		scanf("%d", &wines[i]);
		fgetc(stdin);
	}

	total[1][0] = wines[1];

	if (cnt > 1) {
		total[2][0] = wines[2] + wines[1]; 
		total[2][1] = wines[2];
	}

	for (int i = 3; i < cnt + 1; ++i) {
		total[i][0] = max(total[i - 1][1], total[i - 1][2]) + wines[i];
		total[i][1] = max({ total[i - 2][0], total[i - 2][1], total[i - 2][2] }) + wines[i];
		total[i][2] = max({ total[i - 3][0], total[i - 3][1], total[i - 3][2] }) + wines[i];
	}

	printf("%d\n", max({ total[cnt - 1][0], total[cnt][0], total[cnt][1], total[cnt][2] }));

	//for (int i = 1; i < cnt + 1; ++i) {
	//	printf("%d ", wines[i]);
	//}

	return 0;
}