#include	<iostream>
#include	<vector>

using namespace std;

#define MAX 10
#define MODNUM 1000003

int arr_size = 0;
long long a[5 * MAX][5 * MAX];
long long c[5 * MAX][5 * MAX];
long long ans[5 * MAX][5 * MAX];

int N, S, E, T;

void cal(long long ta[5 * MAX][5 * MAX], long long tb[5 * MAX][5 * MAX]) {
	for (int i = 0; i < 5 * N; i++) {
		for (int j = 0; j < 5 * N; j++) {
			c[i][j] = 0;
			for (int k = 0; k < 5 * N; k++)
				c[i][j] += (ta[i][k] * tb[k][j]);
			c[i][j] %= MODNUM;
		}
	}

	for (int i = 0; i < 5 * N; i++)
		for (int j = 0; j < 5 * N; j++)
			ta[i][j] = c[i][j];
}

int main() {
	char line[MAX + 1];

	// input
	cin >> N >> S >> E >> T;
	S--; E--;
	arr_size = 5 * N;
	for (int i = 0; i < 5 * N; i++)
		ans[i][i] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 1; j < 5; j++)
			a[i * 5 + j][i * 5 + j - 1] = 1;
	for (int i = 0; i < N; i++) {
		scanf("%s", line);
		for (int j = 0; j < N; j++) {
			int t = line[j] - '0';
			if (t == 1) a[i * 5][j * 5] = 1;
			else if (t > 1) a[i * 5][j * 5 + t - 1] = 1;
		}
	}

	// solution
	while (T > 0) {
		if (T % 2 == 1)
			cal(ans, a);
		cal(a, a);
		T /= 2;
	}

	// output
	cout << ans[S * 5][E * 5] << "\n";

	return 0;
}