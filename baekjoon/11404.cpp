#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 101
#define INF 99999

int graph[MAX][MAX];
int n, m;

void floyd() {
	for (int x = 1; x <= n; x++) {
		for (int from = 1; from <= n; from++) {
			if (graph[from][x] == 0)
				continue;
			for (int to = 1; to <= n; to++) {
				if (graph[x][to] == 0 || from == to)
					continue;
				if (graph[from][to] == 0 || graph[from][to] > graph[from][x] + graph[x][to])
					graph[from][to] = graph[from][x] + graph[x][to];
			}
		}
	}
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		if (!graph[a][b])
			graph[a][b] = c;
		else
			graph[a][b] = min(graph[a][b], c);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}

	return 0;
}