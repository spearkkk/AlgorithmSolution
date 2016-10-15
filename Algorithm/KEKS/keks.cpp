#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int k;
int num[500000];

int main() {
	scanf("%d %d", &n, &k);
	fgetc(stdin);

	int tmp;
	scanf("%d", &tmp);
	for (int i = 0; i < n; ++i) {
		int base = pow(10, n - 1 - i);
		num[i] = tmp / base;
		tmp = tmp % base;
	}

	//for (int i = 0; i < n; ++i) {
	//	printf("%d", num[i]);
	//}

	int* pos = new int[n - k + 1];
	for (int i = 0; i <= n - k; ++i) {
		pos[i] = -1;
	}

	for (int i = 1; i <= n - k; ++i) {
		//printf("%d %d\n", pos[i - 1] + 1, k + i - 1);
		pos[i] = max_element(num + pos[i - 1] + 1, num + k + i) - num;
	}

	for (int i = 1; i <= n - k; ++i) {
		printf("%d", num[pos[i]]);
	}

	return 0;
}