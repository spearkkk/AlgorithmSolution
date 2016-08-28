/**
* @file		mismatched_brackets.cpp
* @date		2016.08.28.
* @author	spearkkk
* @brief	https://algospot.com/judge/problem/read/FIXPAREN
*/
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

struct data {
	char left_c;
	char right_c;
	int val;
};

char* fix(queue<char> &que_data, queue<char> que_priority);

int main() {
	int cnt;

	scanf("%d", &cnt);
	fgetc(stdin);
	
	for (int i = 0; i < cnt; ++i) {
		queue<char> que_data;
		queue<char> que_priority;
		char c;
		int flg = 0;

		while ((c = fgetc(stdin)) != '\n') {
			if (c == ' ') {
				flg = 1;
				continue;
			}
			if (flg == 0) {
				que_data.push(c);
			}
			else {
				que_priority.push(c);
			}
		}
		printf("%s\n", fix(que_data, que_priority));
	}

	return 0;
}

char* fix(queue<char> &que_data, queue<char> que_priority) {
	struct data priority[4];
	char* rslt;
	int len;

	for (int i = 0; i < 4; ++i) {
		priority[i].left_c = que_priority.front();
		switch (priority[i].left_c) {
		case '(':
			priority[i].right_c = ')';
			break;
		case '{':
			priority[i].right_c = '}';
			break;
		case '[':
			priority[i].right_c = ']';
			break;
		case '<':
			priority[i].right_c = '>';
			break;
		}
		priority[i].val = 4 - i;
		que_priority.pop();
	}

	len = que_data.size();
	rslt = new char[len + 1];
	rslt[len] = '\0';
	
	int cnt = 0;
	int idx = 0;
	int cur = 0;
	stack<char> stk;
	while (!que_data.empty()) {
		char c = que_data.front();
		que_data.pop();

		rslt[idx++] = c;

		if (c == '(' || c == '{' || c == '[' || c == '<') {
			stk.push(c);
			++cur;
			++cnt;
		}
		else {
			--cur;
			char left = stk.top();
			char right = c;
			struct data left_data;
			struct data right_data;

			for (int j = 0; j < 4; ++j) {
				if (priority[j].left_c == left) {
					left_data = priority[j];
				}
				if (priority[j].right_c == right) {
					right_data = priority[j];
				}
			}

			if (left_data.val < right_data.val) {
				rslt[cur] = right_data.left_c;
			}
			else if(left_data.val > right_data.val) {
				rslt[idx - 1] = left_data.right_c;
			}
			stk.pop();
			--cnt;

			if (cnt == 0) {
				cur = idx;
			}
		}
	}
	return rslt;
}