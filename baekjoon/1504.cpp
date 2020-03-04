#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;

#define MAX 800 + 1
#define INF 99999999

int n, e;
int trace[MAX];
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> dist(vertex, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// ¾ÈºÁµµ minimum
		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int neighbor = graph[cur][i].first;
			int neighbor_dist = cost + graph[cur][i].second;

			if (dist[neighbor] > neighbor_dist) {
				dist[neighbor] = neighbor_dist;
				trace[neighbor] = cur;
				pq.push(make_pair(neighbor_dist, neighbor));
			}
		}
	}
	return dist;
}

int main() {
	int ans = 0;
	int a, b, c;
	int node1, node2;
	
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	cin >> node1 >> node2;

	vector<int> result = dijkstra(1, n + 1);
	vector<int> temp1 = dijkstra(node1, n + 1);
	vector<int> temp2 = dijkstra(node2, n + 1);

	ans = min((result[node1] + temp1[node2] + temp2[n]), (result[node2] + temp2[node1] + temp1[n]));

	if (ans >= INF || ans < 0)
		cout << "-1\n";
	else
		cout << ans << "\n";

	return 0;
}