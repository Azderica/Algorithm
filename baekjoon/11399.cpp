#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

int main() {
	int N, key;
	int ans = 0;
	cin >> N;

	vector<int> time(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &key);
		time[i] = key;
	}
	sort(time.begin(), time.end());

	for (int i = 0; i < N; i++) {
		ans += time[i] * (N - i);
	}
	printf("%d\n", ans);

	return 0;
}