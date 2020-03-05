#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 10000

int main() {
	long long int n, x, y;
	long long int ans = 0;
	vector<pair<long long int, long long int>> pos;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		pos.push_back(make_pair(x, y));
	}

	// vector ¿ÜÀû
	for (int i = 1; i < n; i++) {
		ans += (pos[0].first * pos[i - 1].second + pos[i - 1].first * pos[i].second + pos[i].first * pos[0].second)
			- (pos[0].second * pos[i - 1].first + pos[i - 1].second * pos[i].first + pos[i].second * pos[0].first);
	}

	printf("%.1lf\n", abs(ans / 2.0));

	return 0;
}