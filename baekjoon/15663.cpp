#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 10

int n, m;
vector<int> arr;
int v[MAX];
bool visited[MAX];

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	int before = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (!visited[i] && (i == 0 || before != arr[i])) {
			before = arr[i];
			v[cnt] = arr[i];

			visited[i] = true;
			dfs(cnt + 1);
			visited[i] = false;
		}
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

	dfs(0);

	return 0;
}