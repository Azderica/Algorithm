#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
#include	<string.h>
using namespace std;

#define MAX 1001

vector<int> *graph;
bool visited[MAX] = { false, };
int N, M, V;

void DFS(int node) {
	visited[node] = true;
	cout << node << " ";

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next])
			DFS(next);
	}
}

void BFS(int node) {
	queue<int> q;
	vector<int>::iterator i;

	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int s = q.front();
		cout << s << " ";
		q.pop();

		for (i = graph[s].begin(); i < graph[s].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

int main() {
	int u, v;

	cin >> N >> M >> V;

	graph = new vector<int>[N + 1];
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(V);
	printf("\n");

	memset(visited, 0, sizeof(visited));
	BFS(V);
	printf("\n");

	return 0;
}