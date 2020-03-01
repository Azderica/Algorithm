#include	<iostream>
#include	<algorithm>
#include	<queue>
using namespace std;

#define MAX 8

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
int lab[MAX][MAX], tmp[MAX][MAX], result;

void bfs() {
	int after_lab[MAX][MAX];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			after_lab[i][j] = tmp[i][j];

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (after_lab[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if(next_x >=0 && next_x < m && next_y >=0 && next_y < n)
				if (after_lab[next_y][next_x] == 0) {
					after_lab[next_y][next_x] = 2;
					q.push(make_pair(next_y, next_x));
				}
		}
	}

	int empty = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (after_lab[i][j] == 0)
				empty++;

	result = max(result, empty);
}

void makeWall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				makeWall(cnt + 1);
				tmp[i][j] = 0;
			}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &lab[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			// if any blank
			if (lab[i][j] == 0) {
				for (int ti = 0; ti < n; ti++)
					for (int tj = 0; tj < m; tj++)
						tmp[ti][tj] = lab[ti][tj];

				tmp[i][j] = 1;
				makeWall(1);
				tmp[i][j] = 0;
			}
		}

	cout << result << "\n";

	return 0;
}