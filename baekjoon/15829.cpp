#include	<iostream>
#include	<math.h>
using namespace std;

int main() {
	int L;
	unsigned long long int ans = 0;
	char* str;

	cin >> L;
	str = new char[L + 1];
	scanf("%s", str);

	unsigned long long int r = 1;
	for (int i = 0; i < L; i++) {
		ans += (str[i] - 'a' + 1) * r;
		ans %= 1234567891;
		r *= 31;
		r %= 1234567891;
	}
	ans %= 1234567891;

	cout << ans;

	return 0;
}