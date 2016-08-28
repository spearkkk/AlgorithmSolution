/**
* @file		uri_decoding.cpp
* @date		2016.08.27.
* @author	spearkkk
* @brief	https://algospot.com/judge/problem/read/URI
*/

#include <iostream>
#include <string>
#include <stdio.h>

#pragma warning(disable:4996)

using namespace std;

string decoding(string str);

int main() {
	int cnt;

	//cin >> cnt;
	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		char str[81];
		string str_s;

		fgets(str, 81, stdin);		
		str_s = str;
		str_s = str_s.substr(0, str_s.length() - 1);
		cout << decoding(str_s) << endl;
	}
	return 0;
}

string decoding(string str) {
	int idx_cur = 0;
	string encoded_strings[17] = { "%20", "%21", "%22","%23","%24", "%25", "%26","%27","%28", "%29", "%2a", "%2b", "%2c", "%2d", "%2e", "%2f"};
	string special_characters[17] = { " ", "!", "\"", "#", "$", "%", "&", "\'", "(", ")", "*", "+", "`", "-", ".", "/"};

	for(int i = 0; i < 17; ++i) {
		int len = str.length();

		while (idx_cur < len - 2 && len > 2) {
			if (str.substr(idx_cur, 3).compare(encoded_strings[i]) == 0) {
				string pre = str.substr(0, idx_cur);
				string post = str.substr(idx_cur + 3, str.length());
				str = pre + special_characters[i] + post;
				//cout << pre << " " << post << endl;
				len = str.length();
			}
			++idx_cur;
		}
		idx_cur = 0;
	}

	return str;
}