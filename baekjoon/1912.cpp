#include <iostream>
using namespace std;

#define COUNT_MAX 100001

int max(int a, int b) {
	if (a >= b)
		return a;
	return b;
}

int main(void) {
	int N;
	int A[COUNT_MAX];
	int SUM[COUNT_MAX];
	int max_num;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	SUM[1] = A[1];
	max_num = A[1];

	for (int i = 2; i <= N; i++) {
		SUM[i] = max(SUM[i - 1] + A[i], A[i]);
		max_num = max(max_num, SUM[i]);
	}
		
	cout << max_num << endl;

	return 0;
}