#include	<iostream>
#include	<algorithm>
#include	<string.h>
using namespace std;

#define MAX 500
#define INF 2147483647

int N;
pair<int, int> arr[MAX];
int dp[MAX][MAX];

int minMul(int left, int right) {
	if (left == right)
		return 0;
	int &res = dp[left][right];
	if (res != -1)
		return res;

	res = INF;
	for (int i = left; i < right; i++)
		res = min(res, minMul(left, i) + minMul(i + 1, right) + arr[left].first * arr[i].second * arr[right].second);
	return res;
}

int main(void) {
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	memset(dp, -1, sizeof(dp));
	int ans = minMul(0, N - 1);

	cout << ans << "\n";

	return 0;
}