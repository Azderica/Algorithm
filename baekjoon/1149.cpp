#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 1001

int N;
int cost[MAX][3] = { 0, };
int ans[MAX][3] = { 0, };

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

	for (int i = 1; i <= N; i++) {
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + cost[i][0];
		ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]) + cost[i][1];
		ans[i][2] = min(ans[i - 1][0], ans[i - 1][1]) + cost[i][2];
	}

	cout << min(min(ans[N][0], ans[N][1]), ans[N][2]) << "\n";

	return 0;
}