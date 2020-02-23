#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;


#define MAX 100001

bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void BFS(int node) {
	queue<int> q;
	vector<int>::iterator i;

	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int s = q.front();
		//cout << s << " ";
		q.pop();

		for (i = tree[s].begin(); i < tree[s].end(); i++) {
			if (!visited[*i]) {
				parent[*i] = s;
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

int main(void) {
	int N;
	int u, v;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for (int i = 2; i <= N; i++)
		sort(tree[i].begin(), tree[i].end());

	BFS(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}