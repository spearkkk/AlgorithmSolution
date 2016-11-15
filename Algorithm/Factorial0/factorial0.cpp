/**
* @file		factorial0.cpp
* @date		2016.11.13.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1676
*/
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;

	scanf("%d", &n);
	fgetc(stdin);

	int cnt = 0;
	int tmp = 0;
	int idx = 1;

	while(true) {
		tmp = pow(5, idx);
		if (n >= tmp) {
			cnt += n / tmp;
			++idx;
		}
		else {
			break;
		}
	}

	printf("%d\n", cnt);
}