#include	<iostream>
#include	<algorithm>
#include	<cstring>
using namespace std;

#define N_MAX 101

int main() {
	int n, m, r;
	int graph[N_MAX][N_MAX] = { 0, };
	int dist[N_MAX][N_MAX];
	int item[N_MAX] = { 0, };
	memset(dist, 0x3f, sizeof(dist));

	// input
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		scanf("%d", &item[i]);
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 0; i < r; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		graph[a][b] = graph[b][a] = l;
		dist[a][b] = dist[b][a] = l;
	}

	// floyd
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

	// ans, find minimum in loop
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++)
			if (dist[i][j] <= m)
				temp += item[j];
		ans = max(ans, temp);
	}
	cout << ans << "\n";

	return 0;
}