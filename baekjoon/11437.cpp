#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;

#define MAX 100000 + 1
queue<int> q;
bool check[MAX];
vector<int> a[MAX];
int depth[MAX], parent[MAX];
int N, M;

// 부모찾아주기
int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	while (depth[u] != depth[v]) {
		u = parent[u];
	}
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main() {
	// input
	int u, v;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	// solution - bfs
	q.push(1);
	check[1] = true;	// 시작노드
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			if (!check[a[x][i]]) {
				depth[a[x][i]] = depth[x] + 1;
				check[a[x][i]] = true;
				parent[a[x][i]] = x;
				q.push(a[x][i]);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		cout << lca(u, v) << "\n";
	}
}