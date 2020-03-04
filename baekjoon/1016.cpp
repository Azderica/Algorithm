#include	<iostream>
using namespace std;

#define MAX 1000000 + 1

bool num[MAX];

int main() {
	long long int min, max;
	int ans = 0;
	cin >> min >> max;

	for (long long i = 2; (i * i) <= max; i++) {
		long long start = min / (i * i);
		if (start * i * i != min)
			start++;	// min <= start < max
		for (long long j = start; i * i * j <= max; j++)
			num[i * i * j - min] = true;
	}

	for (int i = 0; i < max - min + 1; i++)
		if (!num[i])
			ans++;

	cout << ans << "\n";

	return 0;
}