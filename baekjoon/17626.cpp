#include	<iostream>
#include	<math.h>
using namespace std;

int main(void) {
	int N;
	int* squares;

	cin >> N;
	squares = new int[N + 1];
	squares[0] = 0;
	squares[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (pow(int(sqrt(i)), 2) == double(i))
			squares[i] = 1;
		else {
			squares[i] = 50000;
			for (int j = 1; j <= (i / 2); j++) {
				if (squares[j] + squares[i - j] < squares[i])
					squares[i] = squares[j] + squares[i - j];
			} 
		}
	}
	cout << squares[N] << endl;

	return 0;
}