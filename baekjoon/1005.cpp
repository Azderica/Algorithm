#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

int N, K;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> times;
vector<int> d;

int main() {
	int TestCase;
	
	cin >> TestCase;
	// topological sort problem
	while (TestCase--) {
		int X, Y, W;
		graph.clear();
		indegree.clear();
		times.clear();
		d.clear();

		cin >> N >> K;
		graph.resize(N + 1);
		indegree.resize(N + 1);
		times.resize(N + 1);
		d.resize(N + 1);

		for (int i = 1; i <= N; i++)
			scanf("%d", &times[i]);
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			graph[X].push_back(Y);
			indegree[Y]++;
		}
		scanf("%d", &W);

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				d[i] = times[i];
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			int length = graph[now].size();
			for (int i = 0; i < length; i++) {
				int next = graph[now][i];
				indegree[next]--;
				if (d[next] < d[now] + times[next])
					d[next] = d[now] + times[next];
				if (indegree[next] == 0)
					q.push(next);
			}
		}

		cout << d[W] << "\n";
	}
	
	return 0;
}