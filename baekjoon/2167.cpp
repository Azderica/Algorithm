#include	<iostream>

using namespace std;

#define MAX 301

int arr[MAX][MAX] = { 0, };	// input array
int sum[MAX][MAX] = { 0, };	// sum array

int main() {
	int N, M;
	int K;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &arr[i][j]);

	sum[1][1] = arr[1][1];
	for (int j = 2; j <= M; j++)
		sum[1][j] = sum[1][j - 1] + arr[1][j];
	for (int i = 2; i <= N; i++)
		sum[i][1] = sum[i - 1][1] + arr[i][1];

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= M; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + arr[i][j] - sum[i - 1][j - 1];

	int i, j, x, y;
	int ans;
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		ans = (sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]);
		cout << ans << "\n";
	}

	return 0;
}
