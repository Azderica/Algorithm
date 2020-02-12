#include	<iostream>
#include	<algorithm>
using namespace std;

int main(void) {
	int N, M;
	int C[100];
	int sum = 0, tmp;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &C[i]);

	sort(C, C + N);
	
	for (int i = 0; i < N - 2; i++)
		for (int j = i + 1; j < N - 1; j++) {
			if (C[i] + C[j] > M) {
				cout << sum << endl;
				return 0;
			}
			for (int k = j + 1; k < N; k++) {
				tmp = C[i] + C[j] + C[k];
				if (tmp > M)
					break;
				if (tmp > sum)
					sum = tmp;
				if (sum == M) {
					cout << sum << endl;
					return 0;
				}
			}
		}

	cout << sum << endl;

	return 0;
}