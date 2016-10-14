#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1000000000 + 1;

int m;
int n;
int mat[502][502];
int cache[501][501];
int rslt = 0;

int downhill(int i, int j) {
	if (i == m, j == n) {
		++rslt;
		return 1;
	}

	if (cache[i][j] != -1) {
		++rslt;
		return 1;
	}

	if (mat[i][j] > mat[i + 1][j]) {
		if (downhill(i + 1, j) == 1) {
			cache[i + 1][j] = 1;
		}
	}
	if (mat[i][j] > mat[i][j - 1]) {
		if (downhill(i, j - 1) == 1) {
			cache[i][j - 1] = 1;
		}
	}
	if (mat[i][j] > mat[i][j + 1]) {
		if (downhill(i, j + 1) == 1) {
			cache[i][j + 1] = 1;
		}
	}
	if (mat[i][j] > mat[i - 1][j]) {
		if (downhill(i - 1, j) == 1) {
			cache[i - 1][j] = 1;
		}
	}

	return 0;
}

int main() {
	memset(mat, MAX, sizeof(mat));
	memset(cache, -1, sizeof(cache));

	scanf("%d %d", &m, &n);
	fgetc(stdin);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &mat[i][j]);
			fgetc(stdin);
		}
	}

	downhill(1, 1);

	printf("%d\n", rslt);

	return 0;
}