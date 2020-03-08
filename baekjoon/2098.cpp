#include	<iostream>
#include	<algorithm>
#include	<string.h>
using namespace std;

#define MAX 16
#define INF 999999999

int N, cost = 0;
int graph[MAX][MAX];
int cache[MAX][1 << MAX];

int TSP(int here, int visited) {
	if (visited == (1 << N) - 1) {
		if (graph[here][0] != 0)
			return graph[here][0];
		return INF;
	}

	// 메모이제이션
	int &res = cache[here][visited];
	if (res != -1)
		return res;
	res = INF;

	for (int next = 0; next < N; next++) {
		if (visited & (1 << next) || graph[here][next] == 0)
			continue;
		int candiate = graph[here][next] + TSP(next, visited + (1 << next));
		res = min(res, candiate);
	}
	return res;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &graph[i][j]);
	}

	int res = INF;
	memset(cache, -1, sizeof(cache));
	cout << TSP(0, 1) << "\n";

	return 0;
}