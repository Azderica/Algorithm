#include	<iostream>
#include	<string.h>
using namespace std;

#define MAX 100000 + 1

int N, cnt;
int isWant[MAX];
bool visited[MAX];
bool isDone[MAX];

void dfs(int node) {
	visited[node] = true;
	int next = isWant[node];
	if (!visited[next])
		dfs(next);
	else if (!isDone[next]) {
		for (int i = next; i != node; i = isWant[i])
			cnt++;
		cnt++;
	}
	isDone[node] = true;
}

int main() {
	int Testcase;

	cin >> Testcase;
	while (Testcase--) {
		memset(visited, false, sizeof(visited));
		memset(isDone, false, sizeof(isDone));
		cin >> N;

		for (int i = 1; i <= N; i++)
			scanf("%d", &isWant[i]);
		cnt = 0;
		for (int i = 1; i <= N; i++)
			if (!visited[i])
				dfs(i);
		cout << (N - cnt) << "\n";
	}

	return 0;
}