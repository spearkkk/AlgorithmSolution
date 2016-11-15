/**
* @file		bread_sales.cpp
* @date		2016.11.15.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/11052
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int price[1001];
int dp[1001][1001];

int func(int idx, int n) {
	if (n == 0) {
		return 0;
	}

	int& ret = dp[idx][n];
	if (ret != -1) {
		return ret;
	}

	ret = price[idx] + func(n - idx, n - idx);
	if (idx > 0) {
		ret = max(ret, func(idx - 1, n));
	}

	return ret;
}

int main() {
	memset(price, 0, sizeof(price));
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) {
			dp[i][j] = -1;
		}
	}

	scanf("%d", &N);
	fgetc(stdin);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &price[i]);
		fgetc(stdin);
	}

	printf("%d\n", func(N, N));

	return 0;
}