#include	<iostream>
using namespace std;

char arr[3072][6144];

void star(int height, int x, int y) {
	if (height == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	star(height / 2, x, y);
	star(height / 2, x - (height / 2), y + (height / 2));
	star(height / 2, x + (height / 2), y + (height / 2));
}


int main() {
	int n, i, j;

	cin >> n;

	star(n, n - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (arr[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << "\n";
	}

	return 0;
}