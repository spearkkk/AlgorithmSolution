/**
* @file		encrypt.cpp
* @date		2016.08.23.
* @author	spearkkk
* @brief	https://algospot.com/judge/problem/read/ENCRYPT
*/
#include <iostream>
#include <string>

using namespace std;

string encrypt(string str);

int main() {
	int cnt;

	cin >> cnt;
	
	for (int i = 0; i < cnt; ++i) {
		string str;

		cin >> str;
		cout << encrypt(str) << endl;
	}

	return 0;
}
string encrypt(string str) {
	string pre;
	string post;
	int idx = 0;

	while(idx < str.length()) {
		if (idx % 2 == 0) {
			pre += str.at(idx);
		}
		else {
			post += str.at(idx);
		}
		++idx;
	}

	return pre + post;
}