/**
* @file		new_employee.cpp
* @date		2016.09.15.
* @author	spearkkk
* @brief	hhttps://www.acmicpc.net/problem/1946
*/
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void count(vector<pair<int, int>> &rank, int &rslt, int idx);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);
	for (int i = 0; i < cnt; ++i) {
		int cnt_rank;
		scanf("%d", &cnt_rank);
		fgetc(stdin);
		vector<pair<int, int>> rank(cnt_rank);
		for (int j = 0; j < cnt_rank; ++j) {
			scanf("%d %d", &rank[j].first, &rank[j].second);
			fgetc(stdin);
		}

		int rslt = 0;

		sort(rank.begin(), rank.end(), greater<pair<int, int>>());
		count(rank, rslt, cnt_rank - 1);

		printf("%d\n", rslt);
	}
	return 0;
}

void count(vector<pair<int, int>> &rank, int &rslt, int idx) {
	int min_second = rank[idx].second;
	rank.erase(rank.begin() + idx);
	++rslt;
	int cur = idx - 1;
	while (!rank.empty()) {
		if (rank[cur].second > min_second) {
			rank.erase(rank.begin() + cur);
			--cur;
		}
		else {
			count(rank, rslt, cur);
		}
	}
}