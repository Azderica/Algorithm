#include	<iostream>

using namespace std;

int main() {
	long long int n, m;
	int cnt = 0;

	cin >> n >> m;

	while (1) {
		if (n == m) {
			break;
		}

		if (m % 10 == 1) {
			m = m / 10;
			cnt++;
		}
		else if (m % 2 == 0) {
			m = m / 2;
			cnt++;
		}
		else {
			cnt = -2;
			break;
		}

		if (m < n) {
			cnt = -2;
			break;
		}
	}
	cnt++;

	cout << cnt << "\n";

	return 0;
}