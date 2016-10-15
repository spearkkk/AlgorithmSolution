#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int k;
vector<int> seq;
int tap[100];

int main() {
	scanf("%d %d", &n, &k);
	fgetc(stdin);

	memset(tap, 0, sizeof(tap));

	for (int i = 0; i < k; ++i) {
		int tmp;
		scanf("%d", &tmp);
		fgetc(stdin);

		seq.push_back(tmp);
	}

	for (int i = 0; i < seq.size() - 1; ++i) {
		if (seq[i] == seq[i + 1]) {
			seq.erase(seq.begin() + i);
			--i;
		}
	}

	for (int i = 0; i < n && i < seq.size(); ++i) {
		if (find(tap, tap + n, seq[i]) - tap < n) {
			seq.erase(seq.begin() + i);
			--i;
		}
		else {
			tap[i] = seq[i];
		}
	}

	int rslt = 0;

	for (int i = n; i < seq.size(); ++i) {
		if (find(tap, tap + n, seq[i]) - tap < n) {
			continue;
		}

		int flg[100];
		memset(flg, 0, sizeof(flg));

		for (int j = 0; j < n && j + i < seq.size(); ++j) {
			int idx = find(tap, tap + n, seq[j + i]) - tap;
			if (idx < n) {
				flg[idx] = 1;
			}
		}

		for (int j = 0; j < n; ++j) {
			if (flg[j] == 0) {
				tap[j] = seq[i];
				++rslt;
				break;
			}
		}
	}

	printf("%d\n", rslt);

	return 0;
}