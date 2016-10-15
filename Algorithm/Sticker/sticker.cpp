#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int sticker[2][100000];
int val[2][100000];

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		n = 0;
		memset(sticker, 0, sizeof(sticker));
		memset(val, 0, sizeof(val));

		scanf("%d", &n);
		fgetc(stdin);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &sticker[i][j]);
				fgetc(stdin);
			}
		}

		val[0][0] = sticker[0][0];
		val[1][0] = sticker[1][0];
		val[0][1] = sticker[0][1] + val[1][0];
		val[1][1] = sticker[1][1] + val[0][0];

		for (int i = 2; i < n; ++i) {
			val[0][i] = sticker[0][i] + max(val[1][i - 1], val[1][i - 2]);
			val[1][i] = sticker[1][i] + max(val[0][i - 1], val[0][i - 2]);
		}

		printf("%d\n", max(val[0][n - 1], val[1][n - 1]));

	}
}