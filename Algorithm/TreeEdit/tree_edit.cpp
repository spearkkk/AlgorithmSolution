#include <stdio.h>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		string t1;
		string t2;

		getline(cin, t1);
		getline(cin, t2);

		int rslt = 0;
		int dpth = -1;
		int cnt_node_t1[10001] = { 0, };
		int cnt_node_t2[10001] = { 0, };

		vector<pair<int, pair<int, char>>> node_t1;
		vector<pair<int, pair<int, char>>> node_t2;

		for (int i = 0; i < t1.length(); ++i) {
			if (t1.at(i) == '(') {
				++dpth;
				++cnt_node_t1[dpth + 1];
			}
			else if (t1.at(i) == ')') {
				--dpth;
			}
			else {
				node_t1.push_back(pair<int, pair<int, char>>(dpth, pair<int, char>(cnt_node_t1[dpth], t1.at(i))));
			}
		}
		for (int i = 0; i < t2.length(); ++i) {
			if (t2.at(i) == '(') {
				++dpth;
				++cnt_node_t2[dpth + 1];
			}
			else if (t2.at(i) == ')') {
				--dpth;
			}
			else {
				node_t2.push_back(pair<int, pair<int, char>>(dpth, pair<int, char>(cnt_node_t2[dpth], t2.at(i))));
			}
		}

		sort(node_t1.begin(), node_t1.end(), [](const std::pair<int, pair<int, char>> &left, const std::pair<int, pair<int, char>> &right) {
			return left.first < right.first;
		});
		sort(node_t2.begin(), node_t2.end(), [](const std::pair<int, pair<int, char>> &left, const std::pair<int, pair<int, char>> &right) {
			return left.first < right.first;
		});

		int size = node_t1.size() > node_t2.size() ? node_t2.size() : node_t1.size();
		for (int i = 0; i < size;) {
			if (node_t1.at(i) == node_t2.at(i)) {
				node_t1.erase(node_t1.begin() + i);
				node_t2.erase(node_t2.begin() + i);
				--size;
			}
			else {
				++i;
			}
		}

		int cnt_swap = 0;
		int cnt_replcase = 0;

		sort(node_t1.begin(), node_t1.end());
		sort(node_t2.begin(), node_t2.end());

		for (int i = 0; i < size;) {
			if (node_t1.at(i) == node_t2.at(i)) {
				node_t1.erase(node_t1.begin() + i);
				node_t2.erase(node_t2.begin() + i);
				--size;
				++cnt_swap;
			}
			else {
				++i;
			}
		}
		for (int i = 0; i < size;) {
			if (node_t1.at(i).first == node_t2.at(i).first) {
				if (node_t1.at(i).second.first == node_t2.at(i).second.first) {
					node_t1.erase(node_t1.begin() + i);
					node_t2.erase(node_t2.begin() + i);
					--size;
					++cnt_replcase;
				}
				else {
					++i;
				}
			}
			else {
				++i;
			}
		}
		rslt += cnt_swap / 2 + cnt_replcase + node_t1.size() + node_t2.size();

		printf("%d\n", rslt);
	}
	return 0;
}