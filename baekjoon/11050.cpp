#include	<iostream>
using namespace std;

int B[11][11];

int Bi(int n, int r) {
	if (B[n][r] > 0)
		return B[n][r];
	if (r == 0 || n == r)
		return B[n][r] = 1;
	return B[n][r] = Bi(n - 1, r - 1) + Bi(n - 1, r);
}

int main(void) {
	int N, K;

	cin >> N >> K;

	cout << Bi(N, K) << endl;


	return 0;
}