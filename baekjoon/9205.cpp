#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cstring>
using namespace std;

#define MAX 102

bool visited[MAX];
vector<int> graph[MAX];

int distance(const pair<int, int> a, const pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visited[next] == false)
			dfs(next);
	}
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		memset(visited, false, sizeof(visited));

		int x, y;
		vector<pair<int, int>> store;
		
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &x, &y);
			store.push_back(make_pair(x, y));
		}

		for(int i=0; i<n+2; i++)
			for(int j=i+1; j<n+2; j++)
				if (distance(store[i], store[j]) <= 1000) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}

		dfs(0);

		if (visited[n + 1] == true)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}