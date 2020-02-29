#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

#define MAX 1000 + 1
#define INF 99999999

int n, m;
int start_pos, des_pos;
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
			int near = graph[cur_vertex][i].first;
			int near_distance = cost + graph[cur_vertex][i].second;

			// if find minimum distance, update
			if (distance[near] > near_distance) {
				distance[near] = near_distance;
				pq.push(make_pair(-near_distance, near));
			}
		}
	}
	return distance;
}

int main() {
	int u, v, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &c);
		graph[u].push_back(make_pair(v, c));
	}
	cin >> start_pos >> des_pos;

	vector<int> result = dijkstra(start_pos, n + 1);

	cout << result[des_pos] << "\n";

	return 0;
}