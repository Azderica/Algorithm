#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 500+1

int N;
int cost[MAX][MAX] = { 0, };
int ans[MAX][MAX] = { 0, };

int main() {
	cin >> N;

	for (int j = 1; j <= N; j++)
		for (int i = 1; i <= j; i++)
			scanf("%d", &cost[i][j]);

	for(int j=1; j<=N; j++)
		for (int i = 1; i <= N; i++) {
			ans[i][j] = max(ans[i - 1][j - 1], ans[i][j - 1]) + cost[i][j];
		}

	int max_length = 0;
	for (int i = 1; i <= N; i++)
		if (ans[i][N] > max_length)
			max_length = ans[i][N];

	cout << max_length << "\n";

	return 0;
}