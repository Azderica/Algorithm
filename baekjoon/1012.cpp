#include	<iostream>
#include	<cstdio>
#include	<string.h>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int M, N, K;
int Map[50][50] = { 0, };
bool visitied[50][50] = { false, };

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M)
			continue;
		if (Map[next_y][next_x] && !visitied[next_y][next_x]) {
			visitied[next_y][next_x] = true;
			DFS(next_y, next_x);
		}
	}
}

int main() {
	int T;

	cin >> T;
	for (int t = 0; t < T; t++) {
		int x, y;
		int ans = 0;

		cin >> M >> N >> K;

		memset(Map, 0, sizeof(Map));	
		memset(visitied, 0, sizeof(visitied));
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y);
			Map[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (Map[i][j] && !visitied[i][j]) {
					ans++;
					visitied[i][j] = true;
					DFS(i, j);
				}

		cout << ans << "\n";
	}


	return 0;
}