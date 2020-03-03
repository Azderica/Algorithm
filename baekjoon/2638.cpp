#include	<iostream>
using namespace std;

#define MAX 101

int n, m;
int c_map[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
	c_map[y][x] = -1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
			if (c_map[next_y][next_x] == 0)
				dfs(next_x, next_y);
			else if (c_map[next_y][next_x] > 0)
				c_map[next_y][next_x]++;
		}
	}
}

bool isMelted() {
	bool flag = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 1 || c_map[i][j] == 2) {
				c_map[i][j] = 1;
				flag = true;
			}
			else
				c_map[i][j] = 0;
		}
	return flag;
}

int main() {
	int count = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c_map[i][j]);

	while (isMelted()) {
		dfs(0, 0);
		count++;
	}

	cout << count << "\n";

	return 0;
}