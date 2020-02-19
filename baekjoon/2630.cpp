#include	<iostream>

using namespace std;

int blue = 0;
int white = 0;
int** map;

void map_sum(int x_1, int x_2, int y_1, int y_2) {
	int sum = 0;
	for (int j = y_1; j < y_2; j++)
		for (int i = x_1; i < x_2; i++)
			sum += map[i][j];

	if (sum == 0) {
		white++;
	}
	else if (sum == (x_2 - x_1) * (y_2 - y_1)) {
		blue++;
	}
	else {
		map_sum(x_1, (x_2 + x_1) / 2, y_1, (y_2 + y_1) / 2);
		map_sum((x_2 + x_1) / 2, x_2, y_1, (y_2 + y_1) / 2);
		map_sum(x_1, (x_2 + x_1) / 2, (y_2 + y_1) / 2, y_2);
		map_sum((x_2 + x_1) / 2, x_2, (y_2 + y_1) / 2, y_2);
	}
	return;
}

int main() {
	int N;

	cin >> N;
	map = new int* [N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	map_sum(0, N, 0, N);

	printf("%d\n%d\n", white, blue);

	return 0;
}