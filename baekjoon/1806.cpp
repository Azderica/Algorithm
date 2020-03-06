#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 100000
#define INF 99999999

int main() {
	int arr[MAX];
	int N, S;

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int low = 0, high = 0;
	int sum = arr[0];
	int res = INF;

	// two pointer algorithm
	while(low <= high && high < N){
		if (sum < S)
			sum += arr[++high];
		else if (sum == S) {
			res = min(res, high - low + 1);
			sum += arr[++high];
		}
		else {
			res = min(res, high - low + 1);
			sum -= arr[low++];
		}
	}

	if (res == INF)
		res = 0;
	
	cout << res << "\n";

	return 0;
}
