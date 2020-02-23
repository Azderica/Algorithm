#include	<iostream>
#include	<algorithm>
#include	<string>
using namespace std;

#define MAX 101

int N, M;
string combi[MAX][MAX];

string BigNumAdd(string num1, string num2) {
	long long sum = 0;
	string result;

	while(!num1.empty() || !num2.empty() || sum){
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string combination(int n, int r) {
	if (n == r || r == 0)
		return "1";

	string& result = combi[n][r];
	if (result != "")
		return result;
	
	result = BigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
	return result;
}

int main() {
	long long int ans = 1;

	cin >> N >> M;

	cout << combination(N, M) << "\n";

	return 0;
}