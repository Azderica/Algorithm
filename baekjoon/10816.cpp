#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

int main() {
	int N, M, num;
	int* A;

	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);

		cout << upper_bound(A, A + N, num) - lower_bound(A, A + N, num) << " ";

	}
	cout << endl;

	return 0;
}