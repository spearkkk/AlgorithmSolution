#include <cstdio>
#include <cstring>

using namespace std;

int N;
int K;

int dp[1001][1001];

int func(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	int& ret = dp[n][k];

	if (ret != -1) {
		return ret;
	}
	ret = (func(n - 1, k) + func(n - 1, k - 1)) % 10007;

	return ret;
}

int main() {
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) {
			dp[i][j] = -1;
		}
	}

	scanf("%d %d", &N, &K);
	fgetc(stdin);

	printf("%d\n", func(N, K));

	return 0;
}