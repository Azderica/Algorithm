#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

#define MAX 8

int N, M;
vector<int> v;
int arr[MAX];
bool visited[MAX];

void permu(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		arr[idx] = v[i];
		permu(idx + 1);
		visited[i] = false;
	}
}

int main() {
	int num;

	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());

	permu(0);

	return 0;
}