#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int num[100000];
int cache[100000];

int func(int cur) {
	if (n == cur) {		
		return cache[cur] = num[cur];
	}

	int &ret = cache[cur];

	ret = max(num[cur], num[cur] + func(cur + 1));
}

int main() {
	memset(num, 0, sizeof(num));
	memset(cache, 0, sizeof(cache));

	scanf("%d", &n);
	fgetc(stdin);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
		fgetc(stdin);
	}

	func(0);

	printf("%d\n", *max_element(cache, cache + n));

	return 0;
}