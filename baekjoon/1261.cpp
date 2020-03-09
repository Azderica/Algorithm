#include	<iostream>
#include	<queue>
#include	<algorithm>
using namespace std;

#define MAX 100
#define INF 999999999

int N, M, ans;
int miro[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	dist[y][x] = 0;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (miro[ny][nx] == 1) {
				if (dist[ny][nx] > dist[curY][curX] + 1) {
					dist[ny][nx] = dist[curY][curX] + 1;
					q.push({ ny, nx });
				}
			}
			else if (miro[ny][nx] == 0) {
				if (dist[ny][nx] > dist[curY][curX]) {
					dist[ny][nx] = dist[curY][curX];
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main() {
	char line[MAX + 1];

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%s", line);
		for (int j = 0; j < N; j++) {
			miro[i][j] = line[j] - '0';
			dist[i][j] = INF;
		}
	}

	bfs(0, 0);

	cout << dist[M - 1][N - 1] << "\n";

	return 0;
}