#include	<iostream>

using namespace std;

#define MAX 9

int sudoku[MAX][MAX];
bool row[MAX][MAX];
bool col[MAX][MAX];
bool square[MAX][MAX];

void print() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << sudoku[i][j];
		cout << "\n";
	}
}

void dfs(int cnt) {
	int x = cnt / MAX;
	int y = cnt % MAX;

	if (cnt == (MAX * MAX)) {
		print();
		exit(0);
	}

	if (sudoku[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				sudoku[x][y] = i;
				
				dfs(cnt + 1);

				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
				sudoku[x][y] = 0;
			}
		}
	}
	else
		dfs(cnt + 1);
}

int main() {
	char line[10];

	for (int i = 0; i < MAX; i++) {
		scanf("%s", &line);
		for (int j = 0; j < MAX; j++) {
			sudoku[i][j] = line[j] - '0';
			if (sudoku[i][j] != 0) {
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}