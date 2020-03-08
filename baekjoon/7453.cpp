#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 4000

int N;
vector<long long> A, B, C, D;
vector<long long> CD;

int main() {
	cin >> N;
	A.resize(N);	B.resize(N);
	C.resize(N);	D.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);

	sort(A.begin(), A.end());	sort(B.begin(), B.end());

	for (int c = 0; c < N; c++)
		for (int d = 0; d < N; d++)
			CD.push_back(C[c] + D[d]);

	sort(CD.begin(), CD.end());

	long long ans = 0;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			long long half = A[a] + B[b];

			long long low = lower_bound(CD.begin(), CD.end(), -half) - CD.begin();
			long long high = upper_bound(CD.begin(), CD.end(), -half) - CD.begin();

			if (-half == CD[low])
				ans += (high - low);
		}
	}

	cout << ans << "\n";


	return 0;
}