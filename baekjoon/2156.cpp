#include <iostream>
using namespace std;

int max(int a, int b, int c) {
	if (a >= b) {
		if (a >= c)
			return a;
		else
			return c;
	}
	else {
		if (b >= c)
			return b;
		else
			return c;
	}
}

int main(void) {
	int T;	// test case
	int W[10001];			// wine
	int P[10001];			// maximum wine

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> W[i];
	}

	P[0] = 0;
	P[1] = W[1];
	P[2] = W[1] + W[2];
	for (int i = 3; i <= T; i++) {
		P[i] = max(P[i - 1], P[i - 2] + W[i], P[i - 3] + W[i - 1] + W[i]);
	}

	cout << P[T] << endl;

	return 0;
}