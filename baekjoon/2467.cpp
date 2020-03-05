#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

bool desc(long long a, long long b) {
	return a > b;
}

int main() {
	int n, i = 0, j = 0;
	int key_i = 0, key_j = 0;
	long long num;
	vector<long long> nega, posi;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &num);
		if (num < 0)
			nega.push_back(num);
		else
			posi.push_back(num);
	}

	sort(nega.begin(), nega.end(), desc);
	sort(posi.begin(), posi.end());

	// only positive num
	if (nega.size() == 0) {
		cout << posi[0] << " " << posi[1] << "\n";
	}
	// only negative num
	else if (posi.size() == 0) {
		cout << nega[1] << " " << nega[0] << "\n";
	}
	// general
	else {
		long long int tmp, check = nega[0] + posi[0];
		while (i < nega.size() && j < posi.size()) {
			tmp = nega[i] + posi[j];
			if (abs(tmp) < abs(check)) {
				key_i = i;
				key_j = j;
				check = tmp;
			}
			if (tmp < 0)
				j++;
			else if (tmp > 0)
				i++;
			else {
				key_i = i;
				key_j = j;
				break;
			}
		}
		cout << nega[key_i] << " " << posi[key_j] << "\n";
	}

	return 0;
}