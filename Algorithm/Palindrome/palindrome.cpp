#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int dp[2000][2000];

bool isPal(const string& str, int l, int r) {
	if (l >= r) {
		return true;
	}
	else if (str[l] == str[r]) {
		return isPal(str, l + 1, r - 1);
	}
	else {
		return false;
	}

}

int find(const string & str, int idx, int len) {
	if (idx == str.length()) {
		return 0;
	}

	int &ret = dp[idx][len];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int i = 1; i <= str.length() - idx; ++i) {
		if (isPal(str, idx, idx + i - 1)) {
			ret = min(ret, find(str, idx + i, i) + 1);
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);

	for (int i = 0; i < 2000; ++i) {
		for (int j = 0; j < 2000; ++j) {
			dp[i][j] = -1;
		}
	}

	string str;
	getline(cin, str);

	if(isPal(str, 0, str.size() - 1)) {
		cout << 1 << '\n';
	}
	else {
		cout << find(str, 0, 0) << '\n';
	}

	return 0;
}