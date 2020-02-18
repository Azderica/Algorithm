#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

void BinarySearch(int* arr, int low, int high, int value) {
	if (low > high) {
		cout << "0\n";
		return;
	}
	else {
		int mid = (low + high) / 2;
		if (value > arr[mid])
			return BinarySearch(arr, mid + 1, high, value);
		else if (value < arr[mid])
			return BinarySearch(arr, 0, mid-1, value);
		else {
			cout << "1\n";
			return;
		}
	}
}

int main(){
	int N, M;
	int* A, *B;

	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A, A + N);
	cin >> M;
	B = new int[M];
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);
	for (int i = 0; i < M; i++)
		BinarySearch(A, 0, N - 1, B[i]);

	return 0;
}