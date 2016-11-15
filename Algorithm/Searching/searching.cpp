/**
* @file		searching.cpp
* @date		2016.11.14.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1786
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> getpi(string ptn) {
	int n = ptn.size();
	vector<int> pi(n, 0);

	int b = 1;
	int m = 0;
	
	while (b < n) {
		if (ptn[b + m] == ptn[m]) {
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

vector<int> search(string str, string ptn) {
	vector<int> rslt;

	vector<int> pi = getpi(ptn);

	int n = str.size();
	int n2 = ptn.size();

	int b = 0;
	int m = 0;
	
	while (b + m <= n) {
		if (str[b + m] == ptn[m] && m < n2) {
			++m;
			if (m == n2) {
				rslt.push_back(b);
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
	return rslt;
}
int main() {
	string str;
	string ptn;

	cin.sync_with_stdio(false);

	getline(cin, str);
	getline(cin, ptn);

	vector<int> rslt = search(str, ptn);

	printf("%d\n", rslt.size());
	for (int i = 0; i < rslt.size(); ++i) {
		printf("%d\n", rslt[i] + 1);
	}

	return 0;
}