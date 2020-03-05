#include	<iostream>
using namespace std;

#define MAX 1000000 + 1

int result[MAX] = { 0, };
int trace[MAX] = { 1, };

int main() {
	long long int n;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		result[i] = result[i - 1] + 1;
		trace[i] = i - 1;

		if (i % 3 == 0 && result[i / 3] + 1 < result[i]) {
			result[i] = result[i / 3] + 1;
			trace[i] = i / 3;
		}

		if (i % 2 == 0 && result[i / 2] + 1 < result[i]) {
			result[i] = result[i / 2] + 1;
			trace[i] = i / 2;
		}
	}

	cout << result[n] << "\n";
	for (int i = n; i; i = trace[i])
		cout << i << " ";

	return 0;
}