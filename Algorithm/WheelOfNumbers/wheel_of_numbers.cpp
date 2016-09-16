/**
* @file		wheel_of_numbers.cpp
* @date		2016.09.15.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/11504
*/
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int count(int &cnt_val, int &cnt_seg, vector<int> &x, vector<int> &y, vector<int> &seg);

int main() {
	int cnt;
	
	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		int cnt_seg;
		int cnt_val;

		scanf("%d %d", &cnt_seg, &cnt_val);
		fgetc(stdin);
		vector<int> x(cnt_val);
		vector<int> y(cnt_val);
		vector<int> seg(cnt_seg);

		for (int j = 0; j < cnt_val; ++j) {
			scanf("%d", &x[j]);
			fgetc(stdin);
		}
		for (int j = 0; j < cnt_val; ++j) {
			scanf("%d", &y[j]);
			fgetc(stdin);
		}
		for (int j = 0; j < cnt_seg; ++j) {
			scanf("%d", &seg[j]);
			fgetc(stdin);
		}

		printf("%d\n", count(cnt_val, cnt_seg, x, y, seg));
	}
	return 0;
}

int count(int &cnt_val, int &cnt_seg, vector<int> &x, vector<int> &y, vector<int> &seg) {
	int rslt = 0;

	for (int i = 0; i < cnt_seg; ++i) {
		if (seg[i] >= x[0] && seg[i] <= y[0]) {
			int x_val = 0;
			int y_val = 0;
			int z_val = 0;

			for (int j = 0; j < cnt_val; ++j) {
				x_val += x[j] * pow(10, cnt_val - j - 1);
				y_val += y[j] * pow(10, cnt_val - j - 1);
				z_val += seg[(i + j) % cnt_seg] * pow(10, cnt_val - j - 1);
			}
			if (x_val <= z_val && z_val <= y_val) {
				++rslt;
			}
		}
	}
	return rslt;
}