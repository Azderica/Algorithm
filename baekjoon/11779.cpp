#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

#define MAX 1000 + 1
#define INF 99999999

int n, m;
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
	int u, v, w;
	int s_city, f_city;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
	}
	cin >> s_city >> f_city;

	vector<int> res = dijkstra(s_city, n + 1);
	cout << res[f_city] << "\n";
	
	vector<int> route;
	int node = f_city;
	while (node) {
		route.push_back(node);
		node = trace[node];
	}
	cout << route.size() << "\n";

	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
	cout << "\n";

	return 0;
}