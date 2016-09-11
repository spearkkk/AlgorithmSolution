/**
* @file		def_bfs.cpp
* @date		2016.09.11.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/1260
*/
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int cnt_v;
	int cnt_e;
	int start;

	scanf("%d %d %d", &cnt_v, &cnt_e, &start);
	fgetc(stdin);

	stack<int> stk;
	stk.push(start);

	vector<int> flg_stk(cnt_v + 1, 0);
	vector<int> flg_que(flg_stk);
	vector<vector<int>> mat(cnt_v + 1, vector<int>(cnt_v + 1, 0));

	for (int i = 0; i < cnt_e; ++i) {
		int v1;
		int v2;

		scanf("%d %d", &v1, &v2);
		fgetc(stdin);

		mat[v1][v2] = 1;
		mat[v2][v1] = 1;
	}

	// DFS
	while (!stk.empty()) {
		int v = stk.top();
		stk.pop();

		if (flg_stk[v] == 1) {
			continue;
		}
		else {
			flg_stk[v] = 1;
			for (int i = cnt_v; i > 0; --i) {
				if (mat[v][i] == 1 && flg_stk[i] == 0) {
					stk.push(i);
				}
			}
			printf("%d ", v);
		}
	}
	printf("\n");

	queue<int> que;
	que.push(start);

	// BFS
	while (!que.empty()) {
		int v = que.front();
		que.pop();

		if (flg_que[v] == 1) {
			continue;
		}
		else {
			flg_que[v] = 1;
			for (int i = 1; i < cnt_v + 1; ++i) {
				if (mat[v][i] == 1 && flg_que[i] == 0) {
					que.push(i);
				}
			}
		}
		printf("%d ", v);
	}
	printf("\n");

	//for (int i = 1; i < cnt_v + 1; ++i) {
	//  for (int j = 1; j < cnt_v + 1; ++j) {
	//      printf("%d ", mat[i][j]);
	//  }
	//  printf("\n");
	//}

	return 0;
}