#include	<iostream>
using namespace std;

#define MAX 8

long long a[MAX][MAX] = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};
long long int c[MAX][MAX], ans[MAX][MAX];

void cal(long long ta[MAX][MAX], long long tb[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			c[i][j] = 0;
			for (int k = 0; k < MAX; k++)
				c[i][j] += (ta[i][k] * tb[k][j]);
			c[i][j] %= 1000000007;
		}
	}

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			ta[i][j] = c[i][j];
}

// ÀÎÁ¢Çà·Ä°ö
int main() {
	int d;

	cin >> d;

	for (int i = 0; i < MAX; i++) {
		ans[i][i] = 1;
	}

	while (d > 0) {
		if (d % 2 == 1)
			cal(ans, a);
		cal(a, a);
		d /= 2;
	}

	cout << (ans[0][0] % 1000000007) << "\n";

	return 0;
}