#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

bool comp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main(void) {
	int N;
	vector<string> word;
	vector<string>::iterator iter, iter_end;
	string tmp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		word.push_back(tmp);
	}
	
	sort(word.begin(), word.end(), comp);

	iter_end = unique(word.begin(), word.end());
	
	for (iter = word.begin(); iter != iter_end; iter++) {
		cout << *iter << endl;
	}

	return 0;
}