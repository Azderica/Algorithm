#include	<iostream>
#include	<vector>
#include	<climits>
#include	<algorithm>
using namespace std;

#define MAX 5000

int main() {
	long long num, minimum;
	int idx1, idx2, idx3;
	int N;
	vector<long long> liquid;
	
	cin >> N;
	liquid.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &liquid[i]);

	sort(liquid.begin(), liquid.end());

	minimum = LLONG_MAX;
	for (int i = 0; i < N; i++) {
		int j = i + 1;
		int k = N - 1;

		while (1) {
			if (j >= k)
				break;
			long long sum = liquid[i] + liquid[j] + liquid[k];
			if (llabs(sum) < minimum) {
				minimum = llabs(sum);
				idx1 = i;
				idx2 = j;
				idx3 = k;
			}
			if (sum < 0)
				j++;
			else
				k--;
		}
	}

	cout << liquid[idx1] << " " << liquid[idx2] << " " << liquid[idx3] << "\n";

	return 0;
}