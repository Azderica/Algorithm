#include	<iostream>
#include	<algorithm>
using namespace std;

#define N_MAX 100000 + 1

int n;
int sticker[N_MAX][2];
int sum[N_MAX][3] = { 0, };

int main() {
	int T;

	cin >> T;
	while (T--) {
		cin >> n;

		// input
		for (int i = 1; i <= n; i++)
			scanf("%d", &sticker[i][0]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &sticker[i][1]);

		// sum [0] - no select
		//     [1] - select upper sticker
		//     [2] - select lower sticker
		for (int i = 1; i <= n; i++) {
			sum[i][0] = max(max(sum[i - 1][0], sum[i - 1][1]), sum[i - 1][2]);
			sum[i][1] = max(sum[i - 1][0], sum[i - 1][2]) + sticker[i][0];
			sum[i][2] = max(sum[i - 1][0], sum[i - 1][1]) + sticker[i][1];
		}

		// ans
		int ans;
		ans = max(max(sum[n][0], sum[n][1]), sum[n][2]);

		cout << ans << "\n";
	}

	return 0;
}