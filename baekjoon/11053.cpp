#include	<iostream>
#include	<vector>
using namespace std;

int main() {
	int N, num;
	int find_i, size = 0;
	int A[1000];

	cin >> N;

	scanf("%d", &num);
	A[0] = num;
	size++;

	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		find_i = size;
		for (int j = size - 1; j >= 0; j--) {
			if (A[j] >= num) {
				find_i = j;
			}
		}
		A[find_i] = num;
		if (find_i != size)
			size--;
		size++;
	}

	cout << size << "\n";

	return 0;
}