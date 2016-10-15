#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int num[100000];
int cache[100000];
int cache2[100000];

int func(int cur) {
	if (n - 1 == cur) {
		return cache[cur] = num[cur];
	}

	int &ret = cache[cur];

	ret = max(num[cur], num[cur] + func(cur + 1));
	cache2[cur] = cache[cur] - cache[cur + 1];

	return ret;
}

int main() {
	memset(num, 0, sizeof(num));
	memset(cache, 0, sizeof(cache));
	memset(cache2, 0, sizeof(cache2));

	scanf("%d", &n);
	fgetc(stdin);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
		fgetc(stdin);
	}

	func(0);
	//printf("%d\n", *max_element(cache, cache + n));

	int p = min_element(cache2, cache2 + n - 1) - cache2;

	num[p] = 0;

	func(0);

	printf("%d\n", *max_element(cache, cache + n));

	return 0;
}