#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 1000 + 1

int n, A[MAX];
int dp[MAX], re_dp[MAX];

int main() {
	int ans = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
			if (A[i] > A[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
	}

	for (int i = n; i >= 1; i--) {
		re_dp[i] = 1;
		for (int j = n; j >= i; j--)
			if (A[i] > A[j] && re_dp[i] < re_dp[j] + 1)
				re_dp[i] = re_dp[j] + 1;
	}

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i] + re_dp[i] - 1);

	cout << ans << endl;


	return 0;
}
