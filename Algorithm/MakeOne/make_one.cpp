/**
* @file		make_one.cpp
* @date		2016.08.24.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1463
*/

#include <iostream>

using namespace std;

int find(unsigned int n);

int main() {
	unsigned int n;

	cin >> n;
	cout << find(n) << endl;

	return 0;
}
int find(unsigned int n) {
	if (n == 1) {
		return 0;
	}
	int a = 99;
	int b = 99;
	int c = 99;

	if (n % 3 == 0) {
		a = 1 + find(n / 3);
	}
	if (n % 3 == 1 || n % 3 == 2) {
		b = 1 + find(n - 1);
	}
	if (n % 2 == 0) {
		c = 1 + find(n / 2);
	}

	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b < c) {
			return b;
		}
		else {
			return c;
		}
	}
}