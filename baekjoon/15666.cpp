#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 10

int n, m;
vector<int> arr, v;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	int key;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		arr.push_back(key);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	n = arr.size();

	dfs(0, 0);

	return 0;
}