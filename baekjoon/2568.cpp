#include	<iostream>
#include	<vector>
#include	<stack>
#include	<algorithm>
using namespace std;

#define MAX 500000 + 1

pair<int, int> conn[MAX];
pair<int, int> ans[MAX];
int cache[MAX];
int N;
bool visited[MAX];
stack<int> s;

int LIS() {
	int idx = 0;
	int length = 0;
	cache[idx] = conn[0].second;
	ans[0] = { 0, conn[0].first };

	for (int i = 1; i < N; i++) {
		if (cache[idx] < conn[i].second) {
			cache[++idx] = conn[i].second;
			ans[i] = { idx, conn[i].first };
		}
		else {
			int idx2 = lower_bound(cache, cache + idx, conn[i].second) - cache;
			cache[idx2] = conn[i].second;
			ans[i] = { idx2, conn[i].first };
		}
	}
	return idx + 1;
}

int main() {
	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &conn[i].first, &conn[i].second);
		visited[conn[i].first] = true;
	}

	// solution
	sort(conn, conn + N);
	int res = LIS();
	cout << N - res << "\n";

	int num = res - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (ans[i].first == num) {
			s.push(ans[i].second);
			num--;
		}
	}

	// 해당 index는 연결되어 있으므로 빼준다.
	while (!s.empty()) {
		visited[s.top()] = false;
		s.pop();
	}


	// output
	for (int i = 0; i < MAX; i++)
		if (visited[i])
			printf("%d\n", i);

	return 0;
}