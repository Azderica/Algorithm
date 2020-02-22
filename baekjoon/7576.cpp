#include	<iostream>
#include	<queue>
using namespace std;

#define MAX 1000

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int box[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
queue<pair<int, int>> q;
int M, N, ans = 0;

bool isStatebox() {
	for (int j = 0; j < N; j++)
		for (int i = 0; i < M; i++)
			if (box[i][j] == 0)
				return false;
	return true;
}

bool isInBox(int x, int y) {
	if (x < 0 || x >= M)
		return false;
	if (y < 0 || y >= N)
		return false;
	return true;
}

void BFS() {
	while (!q.empty()) {
		int q_size = q.size();
		for (int qs = 0; qs < q_size; qs++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (isInBox(nx, ny)) {
					if (box[nx][ny] == 0) {
						box[nx][ny] = 1;
						q.push(pair<int, int>(nx, ny));
					}
				}
			}
			if (q.size() == 0 && isStatebox()) {
				cout << ans << "\n";
				return;
			}
			if (q.size() == 0 && !isStatebox()) {
				cout << -1 << "\n";
				return;
			}
		}
		ans++;
	}

}

int main() {
	cin >> M >> N;

	for (int j = 0; j < N; j++)
		for (int i = 0; i < M; i++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				q.push(pair<int, int>(i, j));
		}

	BFS();


	return 0;
}