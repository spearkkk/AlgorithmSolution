/**
* @file		cattleshed_allocation.cpp
* @date		2016.09.14.
* @author	spearkkk
* @brief	https://www.acmicpc.net/problem/2188
*/
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool BFS(vector<vector<int>> &mat, vector<int> &flg_visited, int v_start, int v_end);

int main() {
	int cnt_cow;
	int cnt_room;

	scanf("%d %d", &cnt_cow, &cnt_room);
	fgetc(stdin);

	vector<vector<int>> mat(cnt_cow + cnt_room + 2, vector<int>(cnt_cow + cnt_room + 2, 0));

	for (int i = 1; i < cnt_cow + 1; ++i) {
		mat[0][i] = 1;
	}
	for (int i = 0; i < cnt_room; ++i) {
		mat[cnt_cow + 1 + i][cnt_cow + cnt_room + 1] = 1;
	}

	for (int i = 1; i < cnt_cow + 1; ++i) {
		int cnt;

		scanf("%d ", &cnt);
		for (int j = 0; j < cnt; ++j) {
			int tmp;
			scanf("%d", &tmp);
			fgetc(stdin);
			mat[i][tmp + cnt_cow] = 1;
		}
	}

	int rslt = 0;

	while (true) {
		vector<int> flg_visited(cnt_cow + cnt_room + 2, -1);
		if (BFS(mat, flg_visited, 0, cnt_cow + cnt_room + 1)) {
			++rslt;
		}
		else {
			break;
		}
	}

	printf("%d\n", rslt);

	return 0;
}

bool BFS(vector<vector<int>> &mat, vector<int> &flg_visited, int v_start, int v_end) {
	bool flg = false;
	queue<int> que;
	que.push(v_start);
	flg_visited[v_start] = v_start;

	while (!que.empty()) {
		int v = que.front();

		que.pop();

		if (v == v_end) {
			flg = true;
		}

		for (int i = 0; i < mat.size(); ++i) {
			if (mat[v][i] == 1 && flg_visited[i] == -1) {
				que.push(i);
				flg_visited[i] = v;
			}
		}
	}

	if (flg) {
		for (int i = v_end; i != v_start; i = flg_visited[i]) {
			mat[flg_visited[i]][i] = -1;
			mat[i][flg_visited[i]] = 1;
		}
		flg_visited[v_start] = -1;
	}

	return flg;
}