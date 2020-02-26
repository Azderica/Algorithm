#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>

using namespace std;

// fail function
// https://blog.naver.com/kks227/220917078260
vector<int> preprocessing(string P) {
	int m = P.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else
			pi[i] = 0;
	}
	return pi;
}


vector<int> kmp(string T, string P) {
	vector<int> pi = preprocessing(P);
	vector<int> ans;
	int n = T.size();
	int m = P.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}

int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> match = kmp(T, P);
	
	int m = match.size();
	cout << m << "\n";
	for (int i = 0; i < m; i++)
		printf("%d ", match[i] + 1);
	cout << "\n";

	return 0;
}