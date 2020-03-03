#include	<iostream>

using namespace std;

#define MAX 6

int n;
long long int a[6][6], b;
long long int c[6][6], ans[6][6];

void cal(long long ta[6][6], long long tb[6][6]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[i][j] = 0;
			for (int k = 1; k <= n; k++)
				c[i][j] += (ta[i][k] * tb[k][j]);
			c[i][j] %= 1000;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ta[i][j] = c[i][j];
}

int main() {

	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
		ans[i][i] = 1;
	}
	

	while (b > 0) {
		if (b % 2 == 1)
			cal(ans, a);
		cal(a, a);
		b /= 2;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

	return 0;
}