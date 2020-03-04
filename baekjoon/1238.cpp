#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;

#define INF 99999999
#define MAX 1000 + 1

int n, m, x;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> dist(vertex, INF);
	dist[start] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int neighbor = graph[cur][i].first;
			int neighbor_dist = cost + graph[cur][i].second;

			if (dist[neighbor] > neighbor_dist) {
				dist[neighbor] = neighbor_dist;
				pq.push(make_pair(neighbor_dist, neighbor));
			}
		}
	}
	return dist;
}

int main() {
	int from, to, t;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &t);
		graph[from].push_back(make_pair(to, t));
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> tmp1 = dijkstra(i, n + 1);
		vector<int> tmp2 = dijkstra(x, n + 1);

		if (tmp1[x] + tmp2[i] >= INF || tmp1[x] + tmp2[i] < 0)
			continue;
		res = max(res, tmp1[x] + tmp2[i]);
	}
	cout << res << "\n";
	return 0;
}