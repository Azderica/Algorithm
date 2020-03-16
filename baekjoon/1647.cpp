#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 100000 + 1

int N, M, ans = 0;
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
	// input
	int start_pos, end_pos, weight;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start_pos, &end_pos, &weight);
		graph.push_back({ weight, {start_pos, end_pos} });
	}

	// solution
	int max_value = 0;
	sort(graph.begin(), graph.end());
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++) {
		if (simpleFind(graph[i].second.first) != simpleFind(graph[i].second.second)) {
			simpleUnion(graph[i].second.first, graph[i].second.second);
			ans += graph[i].first;
			if (graph[i].first > max_value)
				max_value = graph[i].first;
		}
	}
	ans -= max_value;

	// output
	cout << ans << "\n";

	return 0;
}