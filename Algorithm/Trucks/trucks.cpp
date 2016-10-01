/**
* @file		trucks.cpp
* @date		2016.10.01.
* @author	spearkkk
* @brief	2016 ACM ICPC Regional DAEJOEN Problem L
*/
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int trucks;
	int len;
	int max_weight;
	int cur_weight = 0;
	int cnt = 0;
	queue<int> bridge;
	queue<int> weight;

	scanf("%d %d %d", &trucks, &len, &max_weight);
	fgetc(stdin);

	for (int i = 0; i < trucks; ++i) {
		int tmp;
		scanf("%d", &tmp);
		fgetc(stdin);

		weight.push(tmp);
	}

	for (int i = 0; i < len; ++i) {
		bridge.push(0);
	}

	while(!weight.empty()) {
		++cnt;		/// time + 1

		int w = bridge.front();
		bridge.pop();
		cur_weight -= w;

		w = weight.front();
		if (cur_weight + w > max_weight) {
			bridge.push(0);
		}
		else {
			bridge.push(w);
			weight.pop();
			cur_weight += w;
		}
	}
	while(cur_weight != 0) {
		++cnt;

		int w = bridge.front();
		bridge.pop();
		cur_weight -= w;
	}
	printf("%d\n", cnt);
	return 0;
}