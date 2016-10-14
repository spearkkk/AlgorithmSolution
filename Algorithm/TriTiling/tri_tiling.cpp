#include <cstdio>
#include <cstring>

using namespace std;

int n;
int cache[32];

int main() {
	scanf("%d", &n);
	fgetc(stdin);

	memset(cache, 0, sizeof(cache));

	cache[0] = 1;
	cache[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		cache[i] = 3 * cache[i - 2];
		for (int j = 4; j <= i; j += 2) {
			cache[i] += 2 * cache[i - j];
		}
	}

	printf("%d\n", cache[n]);
	return 0;
}