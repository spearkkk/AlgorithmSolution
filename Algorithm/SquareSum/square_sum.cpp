/**
* @file		square_sum.cpp
* @date		2016.11.15.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1699
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int INF = 9887654321;

using namespace std;

int N;
int dp[1000001];

int func(int n) {
	int& ret = dp[n];

	if (n == 0) {
		return 0;
	}

	if (ret != -1) {
		return ret;
	}

	ret = INF;

	int m = sqrt(n);
	for (int i = 1; i <= m; ++i) {
		int r = n - i * i;
		ret = min(ret, 1 + func(r));
	}

	return ret;
}

int main() {
	for (int i = 0; i < 1000001; ++i) {
		dp[i] = -1;
	}

	scanf("%d", &N);
	fgetc(stdin);

	printf("%d\n", func(N));

	return 0;
}