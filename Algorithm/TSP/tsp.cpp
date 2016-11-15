/**
* @file		tsp.cpp
* @date		2016.11.14.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2098
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int W[16][16];
int dp[16][1 << 16];

int TSP(int cur, int visited) {
	int &ret = dp[cur][visited];

	if (ret != -1) {
		return ret;
	}
	if (visited == (1 << N) - 1) {
		if (W[cur][0] != 0) {
			return W[cur][0];
		}
		else {
			return INF;
		}
	}

	ret = INF;
	for (int i = 0; i < N; ++i) {
		if (visited & (1 << i) || W[cur][i] == 0) {
			continue;
		}
		ret = min(ret, TSP(i, visited | (1 << i)) + W[cur][i]);
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &W[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", TSP(0, 1));
}