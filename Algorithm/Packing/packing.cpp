#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int capacity;

int volume[100];
int need[100];
char name[21][100];

int cache[1001][100];

int  pack(int capacity, int item);
void reconstruct(int capacity, int item, vector<char*>& picked);

int main() {
	int cnt;
	
	scanf("%d", &cnt);
	fgetc(stdin);

	for (int i = 0; i < cnt; ++i) {
		memset(volume, 0, sizeof(volume));
		memset(need, 0, sizeof(need));
		memset(name, 0, sizeof(name));
		memset(cache, -1, sizeof(cache));

		scanf("%d %d", &n, &capacity);
		fgetc(stdin);

		for (int j = 0; j < n; ++j) {
			scanf("%s %d %d", &name[j], &volume[j], &need[j]);
			fgetc(stdin);
		}

		//for (int j = 0; j < n; ++j) {
		//	printf("%s %d %d\n", name[j], volume[j], need[j]);
		//}

		vector<char*> picked;
		reconstruct(capacity, 0, picked);
		printf("%d %d\n", pack(capacity, 0), picked.size());

		for (int j = 0; j < picked.size(); ++j) {
			printf("%s\n", picked[j]);
		}
	}

	return 0;
}

int pack(int capacity, int item) {
	if (item == n) {
		return 0;
	}

	int& ret = cache[capacity][item];
	if (ret != -1) {
		return ret;
	}

	ret = pack(capacity, item + 1);

	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}

	return ret;
}

void reconstruct(int capacity, int item, vector<char*>& picked) {
	if (item == n){
		return ;
	}
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}