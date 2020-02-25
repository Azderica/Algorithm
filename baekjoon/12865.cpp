#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define SIZE 100001
#define BAG 101

int N, K;
int W[BAG], V[BAG];	// weight, value
int max_v[SIZE];

void sol() {
	for (int i = 1; i <= N; i++)
		for (int j = K; j >= 1; j--)
			if (W[i] <= j)
				max_v[j] = max(max_v[j], max_v[j - W[i]] + V[i]);
	cout << max_v[K] << "\n";
}

int main() {
	int w, v;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}
	
	sol();

	return 0;
}