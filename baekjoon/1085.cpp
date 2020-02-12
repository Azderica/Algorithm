#include	<iostream>
using namespace std;

int min(int a, int b, int c, int d) {
	int ans = c;
	
	if (a < ans)
		ans = a;
	if (b < ans)
		ans = b;
	if (c < ans)
		ans = c;
	if (d < ans)
		ans = d;
	return ans;
}

int main(void) {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	cout << min(h - y, y, x, w - x) << endl;

	return 0;
}