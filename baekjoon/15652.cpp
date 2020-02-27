#include	<iostream>
using namespace std;

#define	MAX 8

int n, m;
int arr[MAX];
int select[MAX];

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << select[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		select[cnt] = arr[i];
		dfs(i, cnt + 1);
	}
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i - 1] = i;

	dfs(0, 0);

	return 0;
}