#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cstring>
using namespace std;

#define MAX 100000 + 1

int dist[MAX];
bool visited[MAX];
vector<vector<pair<int, int>>> tree;
int n, f, s;

int dfs(int x) {
	visited[x] = true;
	int ret = x;
	dist[x] = 0;
	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i].first;
		int cost = tree[x][i].second;
		if (visited[next])
			continue;
		int ret_next = dfs(next);
		if (dist[x] < dist[next] + cost) {
			dist[x] = dist[next] + cost;
			ret = ret_next;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	tree.resize(n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf(" %d", &x);
		int a, b;
		while (1) {
			scanf(" %d", &a);
			if (a == -1)
				break;
			scanf(" %d", &b);
			tree[x - 1].push_back(make_pair(a - 1, b));
			tree[a - 1].push_back(make_pair(x - 1, b));
		}
	}

	f = dfs(0);
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	s = dfs(f);
	
	cout << dist[f] << endl;

	return 0;
}