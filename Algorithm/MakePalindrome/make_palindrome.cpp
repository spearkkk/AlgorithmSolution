/**
* @file		make_palindrome.cpp
* @date		2016.11.14.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1254
*/
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> getpi(string str) {
	int n = str.size();
	vector<int> pi(n, 0);

	int b = 1;
	int m = 0;

	while (b < n) {
		if (str[b + m] == str[m]) {
			++m;
			pi[b + m - 1] = m;
		}
		else {
			if (m == 0) {
				++b;
			}
			else {
				b += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}

	return pi;
}

int func(string str, string str2) {
	vector<int> pi = getpi(str2);
	int n = str.size();

	int b = 0;
	int m = 0;

	while (b < n) {
		if (str[b + m] == str2[m] && m < n) {
			++m;
			if (b + m == n) {
				return m;
			}
		}
		else {
			if (m == 0) {
				++b;
			}
			else {
				b += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
}

int main() {
	string str;

	cin.sync_with_stdio(false);
	getline(cin, str);

	string str_reverse = str;

	reverse(str_reverse.begin(), str_reverse.end());

	printf("%d\n", 2 * str.size() - func(str, str_reverse));

	return 0;
}