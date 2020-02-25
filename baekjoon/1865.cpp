#include	<iostream>
#include	<vector>
using namespace std;

#define MAX 501
#define INF 999999


int N, M, W;

int main() {
	int TC;

	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		vector<vector<pair<int, int>>> edge(N + 1);
		vector<int> distance(N + 1, INF);
		// start point is 1
		distance[1] = 0;

		// M
		for (int i = 0; i < M; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edge[u].push_back(make_pair(v, w));
			edge[v].push_back(make_pair(u, w));
		}

		// W
		for (int i = 0; i < W; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edge[u].push_back(make_pair(v, (-1 * w)));
		}

		// Bellman-Ford
		bool cycle = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto k : edge[j]) {
					int there = k.first;
					int d = k.second;
					if (distance[j] != INF && (distance[there] > distance[j] + d)) {
						distance[there] = distance[j] + d;
						if (i == N)
							cycle = true;
					}
				}
			}
		}

		if (cycle)
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}