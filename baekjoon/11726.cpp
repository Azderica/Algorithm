#include	<iostream>
#include	<vector>
using namespace std;

int main() {
	int N;

	cin >> N;
	vector<int> tile(N + 1);

	tile[0] = 0;
	tile[1] = 1;
	tile[2] = 2;
	for (int i = 3; i <= N; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 10007;
	}

	cout << tile[N] << "\n";

	return 0;
}