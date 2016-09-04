/**
* @file		log_jumping.cpp
* @date		2016.09.04.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/11497 #ACM-ICPC
*/
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		int cnt_log;
		vector<int> logs;

		scanf("%d", &cnt_log);
		fgetc(stdin);
		for (int j = 0; j < cnt_log; ++j) {
			int tmp;
			scanf("%d", &tmp);
			fgetc(stdin);
			logs.push_back(tmp);
		}

		// 내림 차순으로 정렬
		// functional 라이브러리의 greater<int>()는 내림차순 less<int>()는 오름차순
		// 사용자가 구현한 함수도 가능
		sort(logs.begin(), logs.end(), greater<int>());

		// 처음 두 통나무의 높이의 차
		int max = logs.at(0);
		int min = logs.at(1);
		int diff = max - min;

		// 통나무를 정규분포의 히스토램처럼 배치했을 때의 높이의 차
		for (int i = 0; i < cnt_log - 2; ++i) {
			int tmp = logs.at(i) - logs.at(i + 2);

			if (diff < tmp) {
				diff = tmp;
			}
		}
		// 마지막 두 통나무의 높이의 차
		max = logs.at(cnt_log - 2);
		min = logs.at(cnt_log - 1);
		if (diff < (max - min)) {
			diff = max - min;
		}

		printf("%d\n", diff);
	}

	return 0;
}
