#include	<iostream>
#include	<queue>
using namespace std;

#define MAX 200

// dir
int kdx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int kdy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int K, W, H;
int board[MAX][MAX];
bool visited[MAX][MAX][31];

int bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, int>>> q;	// y, x, K, cnt
	q.push({ {y, x}, {0, 0} });
	visited[y][x][0] = true;

	while (!q.empty()) {
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int knight = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (curY == H - 1 && curX == W - 1)
			return cnt;

		if (knight < K) {
			for (int i = 0; i < 8; i++) {
				int nextY = curY + kdy[i];
				int nextX = curX + kdx[i];

				if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W) {
					if (!visited[nextY][nextX][knight + 1] && !board[nextY][nextX]) {
						visited[nextY][nextX][knight + 1] = true;
						q.push({ { nextY, nextX }, { knight + 1, cnt + 1 } });
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W) {
				if (!visited[nextY][nextX][knight] && !board[nextY][nextX]) {
					visited[nextY][nextX][knight] = true;
					q.push({ { nextY, nextX }, { knight, cnt + 1 } });
				}
			}
		}
	}
	return -1;
}


int main() {
	// input
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			scanf("%d", &board[i][j]);

	// solution
	int ans = bfs(0, 0);

	// output
	cout << ans << "\n";

	return 0;
}