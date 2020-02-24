#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

int main() {
	int N, K;
	int num;
	vector<int> A;

	scanf("%d %d", &N, &K);
	A.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A.begin(), A.end());

	cout << A[K - 1] << "\n";

	return 0;
}