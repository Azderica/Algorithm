#include	<iostream>

using namespace std;

int gcd(int a, int b) {
	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main(void) {
	int a, b;
	int gcd_num;

	scanf("%d %d", &a, &b);
	gcd_num = gcd(a, b);
	cout << gcd_num << endl << (a * b) / gcd_num << endl;

	return 0;
}