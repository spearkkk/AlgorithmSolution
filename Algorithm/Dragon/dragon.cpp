#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void curve(const string& seed, int generation);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		int n;
		int p;
		int l;

		scanf("%d %d %d", &n, &p, &l);
		fgetc(stdin);

		string seed = "FX";
		curve(seed, p);
	}

	return 0;
}

void curve(const string& seed, int generation) {
	if (generation == 0) {
		cout << seed;
		return;
	}

	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X') {
			curve("X+YF", generation - 1);
		}
		else if (seed[i] == 'Y') {
			curve("FX-Y", generation - 1);
		}
		else {
			cout << seed[i];
		}
	}
}
