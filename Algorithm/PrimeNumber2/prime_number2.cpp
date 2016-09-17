#include <stdio.h>

bool is_prime(int number) {
	if (number == 1) {
		return false;
	}
	for (int i = 2; i < number; ++i) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int min;
	int max;
	int prime_total = 0;
	int prime_min = 0;

	scanf("%d", &min);
	fgetc(stdin);
	scanf("%d", &max);
	fgetc(stdin);

	for (int i = min; i < max + 1; ++i) {
		if (is_prime(i)) {
			if (prime_min == 0) {
				prime_min = i;
			}
			prime_total += i;
		}
	}
	if (prime_min == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n%d\n", prime_total, prime_min);
	}
}