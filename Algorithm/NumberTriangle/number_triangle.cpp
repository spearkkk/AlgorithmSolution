/**
* @file		number_triangle.cpp
* @date		2016.09.08.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1932 #dynamic programming
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int cnt;
	int *val;

	scanf("%d", &cnt);
	fgetc(stdin);

	val = new int[cnt + 2];
	for (int i = 0; i < cnt + 2; ++i) {
		val[i] = 0;
	}

	for (int i = 1; i < cnt + 1; ++i) {
		int *tmp = new int[i + 1];
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &tmp[j]);
			fgetc(stdin);
			tmp[j] = tmp[j] + max(val[j - 1], val[j]);
		}
		for (int j = 1; j <= i; ++j) {
			val[j] = tmp[j];
		}
	}
	int *p = max_element(&val[1], &val[cnt + 1]);
	printf("%d\n", *p);

	return 0;
}