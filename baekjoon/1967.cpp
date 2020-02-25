#include	<iostream>
#include	<string.h>
#include	<vector>
using namespace std;

#define MAX 10002

int n, ans = 0, end_point = 0;
bool visited[MAX] = { false, };
vector<pair<int, int>> node[MAX];

void dfs(int point, int length){
	if (visited[point])
		return;
	visited[point] = true;
	if (ans < length) {
		ans = length;
		end_point = point;
	}
	for (int i = 0; i < node[point].size(); i++)
		dfs(node[point][i].first, length + node[point][i].second);
}

int main() {
	cin >> n;
	int parent, child, length;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &parent, &child, &length);
		node[parent].push_back(make_pair(child, length));
		node[child].push_back(make_pair(parent, length));
	}

	// first dfs
	dfs(1, 0);

	ans = 0;
	memset(visited, false, sizeof(visited));

	// second dfs
	dfs(end_point, 0);
	cout << ans << "\n";

	return 0;
}