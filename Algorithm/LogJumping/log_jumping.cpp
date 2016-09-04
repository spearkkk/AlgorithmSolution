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

		// ���� �������� ����
		// functional ���̺귯���� greater<int>()�� �������� less<int>()�� ��������
		// ����ڰ� ������ �Լ��� ����
		sort(logs.begin(), logs.end(), greater<int>());

		// ó�� �� �볪���� ������ ��
		int max = logs.at(0);
		int min = logs.at(1);
		int diff = max - min;

		// �볪���� ���Ժ����� �����䷥ó�� ��ġ���� ���� ������ ��
		for (int i = 0; i < cnt_log - 2; ++i) {
			int tmp = logs.at(i) - logs.at(i + 2);

			if (diff < tmp) {
				diff = tmp;
			}
		}
		// ������ �� �볪���� ������ ��
		max = logs.at(cnt_log - 2);
		min = logs.at(cnt_log - 1);
		if (diff < (max - min)) {
			diff = max - min;
		}

		printf("%d\n", diff);
	}

	return 0;
}
