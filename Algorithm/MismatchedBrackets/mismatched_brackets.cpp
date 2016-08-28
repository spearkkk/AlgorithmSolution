/**
* @file		mismatched_brackets.cpp
* @date		2016.08.28.
* @author	spearkkk
* @brief	https://algospot.com/judge/problem/read/BRACKETS2
*/
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		char c;
		stack<char> stk;
		int flg = 0;

		while ((c = fgetc(stdin)) != '\n') {
			if (flg != 0) {
				continue;
			}
			if(c == '(' || c == '{' || c == '[') {
				stk.push(c);
			}
			else {
				if (stk.empty()) {
					flg = 1;
					continue;
				}
				else {
					switch (stk.top()) {
					case '(':
						if (c != ')') {
							flg = 1;
						}
						else {
							stk.pop();
						}
						break;
					case '{':
						if (c != '}') {
							flg = 1;
						}
						else {
							stk.pop();
						}
						break;
					case '[':
						if (c != ']') {
							flg = 1;
						}
						else {
							stk.pop();
						}
						break;
					default:
						break;
					}
				}
			}
		}
		if (flg == 1) {
			printf("NO\n");
		}
		else if (!stk.empty()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	
	return 0;
}