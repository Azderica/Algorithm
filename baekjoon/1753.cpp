#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

#define MAX 20001
#define INF 9999999

int V, E, K;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	// init INF
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>> pq;	// cost, vertex
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		// minimum cost & vertex
		int cost = -pq.top().first;
		int cur_vertex = pq.top().second;
		pq.pop();

		// get minimum distance
		if (distance[cur_vertex] < cost)
			continue;

		// check neighbor
		for (int i = 0; i < graph[cur_vertex].size(); i++) {
			int neighbor = graph[cur_vertex][i].first;
			int neighbor_distance = cost + graph[cur_vertex][i].second;

			// if find minimum distance, update
			if (distance[neighbor] > neighbor_distance) {
				distance[neighbor] = neighbor_distance;
				pq.push(make_pair(-neighbor_distance, neighbor));
			}
		}
	}
	return distance;
}

int main() {

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int s, d, c;
		scanf("%d %d %d", &s, &d, &c);

		graph[s].push_back(make_pair(d, c));
	}

	vector<int> result = dijkstra(K, V + 1);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}

	return 0;
}