#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>
using namespace std;

#define MAX 10201

int N, g_size;
float answer = 0;
int parent[MAX];
vector<pair<float, pair<int, int>>> graph;
float xpos[101], ypos[101];

float getLength(int a, int b) {
	return sqrt(pow(xpos[a] - xpos[b], 2) + pow(ypos[a] - ypos[b], 2));
}

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
	cin >> N;
	g_size = N * (N + 1) / 2;
	for (int i = 1; i <= N; i++) {
		scanf("%f %f", &xpos[i], &ypos[i]);
	}

	// solution
	for(int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++) {
			graph.push_back({ getLength(i, j), {i, j} });
		}
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < g_size; i++)
		parent[i] = i;
	for (int i = 0; i < graph.size(); i++) {
		if (simpleFind(graph[i].second.first) != simpleFind(graph[i].second.second)) {
			simpleUnion(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}

	// output
	printf("%.2f\n", answer);

	return 0;
}