#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n;
int m;
int capacity[2002][2002];
int flow[2002][2002];

int networkflow(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int total_flow = 0;

	while (true) {
		vector<int> parent(2002, -1);
		parent[source] = source;
		queue<int> q;
		q.push(source);
		
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front();
			q.pop();

			for (int there = 1; there <= 2001; ++there) {
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}

		if (parent[sink] == -1) {
			break;
		}

		int amount = INF;

		for (int p = sink; p != source; p = parent[p]) {
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		}
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}

		total_flow += amount;
	}

	return total_flow;
}

int main() {
	memset(capacity, 0, sizeof(capacity));

	scanf("%d %d", &n, &m);
	fgetc(stdin);

	for (int i = 1; i <= n; ++i) {
		int cnt_work;
		scanf("%d", &cnt_work);
		fgetc(stdin);
		for (int j = 0; j < cnt_work; ++j) {
			int work;
			scanf("%d", &work);
			fgetc(stdin);

			capacity[i][1000 + work] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		capacity[0][i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		capacity[1000 + i][2001] = 1;
	}

	int rslt = networkflow(0, 2001);

	printf("%d\n", rslt);

	return 0;
}