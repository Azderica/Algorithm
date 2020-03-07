#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

#define MAX 32000 + 1

int N, M;
int indegree[MAX];
vector<int> graph[MAX];

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]]--;
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

}

int main() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		indegree[b]++;
	}
	bfs();

	return 0;
}