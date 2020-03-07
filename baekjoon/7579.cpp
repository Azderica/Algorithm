#include	<iostream>
#include	<algorithm>
using namespace std;

// knapsack problem
#define INF 99999999
#define MAX 100 + 1

int byte[MAX];
int cost[MAX];
int dp[MAX][10001];	// c * n <= 10000

int main() {
	int ans = INF;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &byte[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &cost[i]);
	
	dp[0][cost[0]] = byte[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + byte[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= M)
				ans = min(ans, j);
		}
	}

	cout << ans << "\n";

	return 0;
}