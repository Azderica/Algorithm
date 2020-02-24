#include	<iostream>
using namespace std;

int N;
int col[15];
int ans = 0;

// check it is possible position .
bool check(int i) {
	for (int j = 0; j < i; j++)
		if (col[i] == col[j] || abs(col[i] - col[j]) == (i - j))
			return false;
	return true;
}

// Recursive Function, fill col & add ans if that is possible.
void Nqueen(int i) {
	if (i == N)
		ans++;
	else { 
		for (int j = 0; j < N; j++) {
			col[i] = j;
			if (check(i))
				Nqueen(i + 1);
		}
	}
}

int main() {
	
	cin >> N;

	Nqueen(0);

	cout << ans << "\n";

	return 0;
}