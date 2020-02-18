#include	<iostream>
#include	<math.h>
using namespace std;

bool isPrime(unsigned int num) {
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N;
	int ans = 0;
	unsigned int num;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%u", &num);
		if (isPrime(num))
			ans++;
	}

	cout << ans << endl;
	
	return 0;
}