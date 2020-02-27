#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 10

int n, m;
int arr[MAX];
int visited[MAX];

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << visited[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		visited[cnt] = arr[i];
		dfs(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	dfs(0, 0);

	return 0;
}