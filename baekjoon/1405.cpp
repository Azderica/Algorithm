#include	<iostream>
#include	<iomanip>
using namespace std;

#define MAX 30

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool vistied[MAX][MAX];
double result = 0;

double percent[4];
int N;

void dfs(int y, int x, double chance) {
	if (N == 0) {
		result += chance;
		return;
	}
	vistied[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!vistied[ny][nx]) {
			N--;
			dfs(ny, nx, chance * percent[i]);
			N++;
			vistied[ny][nx] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
		percent[i] *= 0.01;
	}

	dfs(15, 15, 1.0);

	cout << fixed;
	cout << setprecision(10) << result << "\n";

	return 0;
}