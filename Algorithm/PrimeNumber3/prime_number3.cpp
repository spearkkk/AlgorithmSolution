/**
* @file		prime_number3.cpp
* @date		2016.09.17.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1929
*/
#include <stdio.h>
#include <vector>

using namespace std;

bool is_prime(int n);

int main() {
	vector<int> prime;
	int min;
	int max;

	scanf("%d %d", &min, &max);
	fgetc(stdin);

	for (int i = min; i < max + 1; ++i) {
		if (is_prime(i)) {
			printf("%d\n", i);
		}
	}
}

bool is_prime(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i * i < n + 1; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}