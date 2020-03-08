#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 1000000

int A[MAX], cache[MAX];
pair<int, int> ans[MAX];
vector<int> print_path;
int N;

int LIS() {
	int idx = 0;
	cache[idx] = A[0];
	ans[0] = { 0, A[0] };

	for (int i = 1; i < N; i++) {
		if (cache[idx] < A[i]) {
			cache[++idx] = A[i];
			ans[i] = { idx, A[i] };
		}
		else {
			int idx2 = lower_bound(cache, cache + idx, A[i]) - cache;
			cache[idx2] = A[i];
			ans[i] = { idx2, A[i] };
		}
	}
	return idx + 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	int result = LIS();
	cout << result << "\n";

	int size = result - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (ans[i].first == size) {
			print_path.push_back(ans[i].second);
			size--;
		}
	}

	for (int i = print_path.size() - 1; i >= 0; i--) {
		cout << print_path[i] << " ";
	}
	cout << "\n";

	return 0;
}