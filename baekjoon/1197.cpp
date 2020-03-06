#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 10000 + 1

int V, E;
int parent[MAX];
vector<pair<int, pair<int, int>>> graph;

int simpleFind(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = simpleFind(parent[x]);
}

void simpleUnion(int x, int y) {
	int x_parent = simpleFind(x);
	int y_parent = simpleFind(y);
	if (x_parent != y_parent)
		parent[x_parent] = y_parent;
}

int main() {
	int start_pos, end_pos, weight;
	long long int ans = 0;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &start_pos, &end_pos, &weight);
		graph.push_back(make_pair(weight, make_pair(start_pos, end_pos)));
	}
	sort(graph.begin(), graph.end());

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		if (simpleFind(graph[i].second.first) != simpleFind(graph[i].second.second)) {
			simpleUnion(graph[i].second.first, graph[i].second.second);
			ans += graph[i].first;
		}
	}

	cout << ans << "\n";
	return 0;
}