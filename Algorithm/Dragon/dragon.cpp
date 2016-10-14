#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int n;
int p;
int l;

const int M = 1000000000 + 100;			/// len의 최댓값
int len[51];

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void precal() {
	len[0] = 1;			/// x를 0번 치환하면, x이기 때문에 1
	for (int i = 1; i < 51; ++i) {
		len[i] = min(M, len[i - 1] * 2 + 2);
	}
}

char expand(const string& seed, int generation, int skip) {
	if (generation == 0) {
		assert(skip < seed.size());
		return seed[skip];
	}

	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X' || seed[i] == 'Y') {
			if (skip >= len[generation]) {
				skip -= len[generation];
			}
			else if(seed[i] == 'X') {
				return expand(EXPAND_X, generation - 1, skip);
			}
			else {
				return expand(EXPAND_Y, generation - 1, skip);
			}
		}
		else if (skip > 0) {
			--skip;
		}
		else {
			return seed[i];
		}
	}
	return '#';
}


int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	precal();

	for (int i = 0; i < cnt; ++i) {
		n = p = l = 0;

		scanf("%d %d %d", &n, &p, &l);
		fgetc(stdin);

		for(int j = p - 1; j < p - 1 + l; ++j) {
			cout<<expand("FX", n, j);
		}
		cout << endl;
	}

	return 0;
}
