#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int b[100001] = { 0, };
int e[100001] = { 0, };

int main() {
	scanf("%d", &n);
	fgetc(stdin);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &b[i], &e[i]);
		fgetc(stdin);
	}

	vector<pair<int, int>> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(e[i], b[i]));
	}
	sort(order.begin(), order.end());

	int next = 0;
	int rslt = 0;

	for (int i = 0; i < order.size(); ++i) {
		int meeting_b = order[i].second;
		int meeting_e = order[i].first;

		if (next <= meeting_b) {
			next = meeting_e;
			++rslt;
		}
	}

	printf("%d\n", rslt);

	return  0;
}