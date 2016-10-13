#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1000000000 + 100;
int bino[201][201];
int skip;

void generate(int n, int m, string s);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < 201; ++i) {
		bino[i][0] = 1;
		bino[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}

	for (int i = 0; i < cnt; ++i) {
		int n;
		int m;
		int k;
		scanf("%d %d %d", &n, &m, &k);
		fgetc(stdin);

		string str = "";
		skip = k - 1;
		generate(n, m, str);
	}
	return 0;
}

void generate(int n, int m, string s) {
	if (skip < 0) {
		return ;
	}
	if (n == 0 && m == 0) {
		//cout << s << endl;
		if (skip == 0) {
			cout << s << endl;
		}
		--skip;
		return ;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) {
		generate(n - 1, m, s + "-");
	}
	if (m > 0) {
		generate(n, m - 1, s + "o");
	}
}