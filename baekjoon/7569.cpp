#include	<iostream>
#include	<queue>
#include	<tuple>
using namespace std;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int box[100][100][100];
bool visited[100][100][100] = { false, };
int M, N, H;
int ans = 0;
queue<tuple<int, int, int>> q;

bool isStatebox() {
	for (int k = 0; k < H; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				if (box[i][j][k] == 0)
					return false;
	return true;
}

bool isInBox(int x, int y, int z) {
	if (x < 0 || x >= M)
		return false;
	if (y < 0 || y >= N)
		return false;
	if (z < 0 || z >= H)
		return false;
	return true;
}

void BFS() {
	while (!q.empty()) {
		int q_size = q.size();
		for (int qs = 0; qs < q_size; qs++) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int z = get<2>(q.front());
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (isInBox(nx, ny, nz)) {
					if (box[nx][ny][nz] == 0) {
						box[nx][ny][nz] = 1;
						q.push(tuple<int, int, int>(nx, ny, nz));
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
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++) {
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1)
					q.push(tuple<int, int, int>(i, j, k));
			}

	BFS();

}