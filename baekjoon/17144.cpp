#include	<iostream>
#include	<queue>
using namespace std;

#define MAX 50 + 1

int r, c, t;
int air_x, air_y;
int room[MAX][MAX];

bool isInRoom(int x, int y) {
	if (x < 0 || x >= c)
		return false;
	if (y < 0 || y >= r)
		return false;
	if (room[y][x] == -1)
		return false;
	return true;
}

void spread() {
	int tmp[MAX][MAX] = { };
	int dx[4] = { -1, 0, 0, 1 };
	int dy[4] = { 0, -1, 1, 0 };

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (room[i][j] != 0 && room[i][j] != -1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int next_x = j + dx[k];
					int next_y = i + dy[k];

					if (isInRoom(next_x, next_y)) {
						tmp[next_y][next_x] += (room[i][j] / 5);
						cnt++;
					}
				}
				room[i][j] -= (room[i][j] / 5) * cnt;
			}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			room[i][j] += tmp[i][j];
}

void cleanup() {
	// (air_x, air_y - 1),(air_x, air_y)
	int tmp[MAX][MAX] = { 0 };

	room[air_y - 1][air_x] = 0;
	room[air_y][air_x] = 0;

	// clockwise
	for (int i = air_y - 2; i >= 1; i--)	// v
		room[i][0] = room[i - 1][0];
	for (int j = 0; j < c - 1; j++)			// <-
		room[0][j] = room[0][j + 1];
	for (int i = 0; i < air_y - 1; i++)		// ^
		room[i][c - 1] = room[i + 1][c - 1];
	for (int j = c - 1; j >= 1; j--)		// ->
		room[air_y - 1][j] = room[air_y - 1][j - 1];
	room[air_y - 1][1] = 0;

	// counter clockwise
	for (int i = air_y + 1; i < r - 1; i++)	// ^
		room[i][0] = room[i + 1][0];
	for (int j = 0; j < c - 1; j++)			// <-
		room[r - 1][j] = room[r - 1][j + 1];
	for (int i = r - 1; i > air_y; i--)		// v
		room[i][c - 1] = room[i - 1][c - 1];
	for (int j = c - 1; j >= 1; j--)		// ->
		room[air_y][j] = room[air_y][j - 1];
	room[air_y][1] = 0;
}

int main() {

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] == -1) {
				air_x = j;
				air_y = i;
			}
		}

	while (t--) {
		spread();
		cleanup();
	}

	int sum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sum += room[i][j];

	cout << sum << "\n";

	return 0;
}