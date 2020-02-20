#include	<iostream>
#include	<vector>
using namespace std;

#define MAX 101

vector<int> graph[MAX];
bool visited[MAX];

void DFS(int node) {
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next])
			DFS(next);
	}
}


int main() {
	int N, M;
	int u, v;
	int ans = -1;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			ans++;
	}

	cout << ans << "\n";

	return 0;
}