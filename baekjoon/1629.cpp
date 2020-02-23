#include	<iostream>

using namespace std;

long long int A, B, C;

long long int pow(long long int x, long long int m) {
	if (m == 0)
		return 1;
	else if (m == 1)
		return x;
	if (m % 2 > 0)
		return pow(x, m - 1) * x;
	long long int half = pow(x, m / 2);
	half %= C;
	return (half * half) % C;
}

int main() {
	scanf("%lld %lld %dlld", &A, &B, &C);

	printf("%lld", pow(A, B) % C);

	return 0;
}