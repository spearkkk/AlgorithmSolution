/**
* @file		kangaroo.cpp
* @date		2016.09.13.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2965
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int kangaroo[3];

	while (scanf("%d %d %d", &kangaroo[0], &kangaroo[1], &kangaroo[2]) != EOF) {
		fgetc(stdin);

		sort(kangaroo, kangaroo + 3);

		printf("%d\n", max(kangaroo[2] - kangaroo[1] - 1, kangaroo[1] - kangaroo[0] - 1));
	}
	return 0;
}