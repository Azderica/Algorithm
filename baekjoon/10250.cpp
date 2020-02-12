#include	<iostream>
using namespace std;

int main(void) {
	int T = 0;
	int H = 0, W = 0, N = 0;
	int x, y;

	cin >> T;
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &H, &W, &N);

		y = N % H;
		if (y == 0) 
			y = H;
		y *= 100;

		x = N / H + 1;
		if (!(N % H))
			x -= 1;

		cout << y + x << endl;
	}

	return 0;
}