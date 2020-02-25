#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

#define MAX 1000

int N, M;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX][2];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int BFS() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = true;

	while (!q.empty())
	{
		// x, y is position
		// b is breaking wall count
		// cnt is length
		int x = q.front().first.first;
		int y = q.front().first.second;
		int b = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1)
			return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == 1 && b == 0) {
					visited[nx][ny][1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(b + 1, cnt + 1)));
				}
				else if (map[nx][ny] == 0 && !visited[nx][ny][b]) {
					visited[nx][ny][b] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(b, cnt + 1)));
				}
			}
		}
	}
	return -1;
}

int main() {
	char text[MAX + 1];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", text);
		for (int j = 0; j < M; j++)
			map[i][j] = text[j] - '0';
	}

	cout << BFS() << "\n";

	return 0;
}