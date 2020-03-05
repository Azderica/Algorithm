#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 1001
char text1[MAX], text2[MAX];
int dp[MAX][MAX];	// max length array
vector<char> lcs_text;

int main() {
	int i = 1, j = 1;
	scanf("%s", text1 + 1);
	scanf("%s", text2 + 1);

	for (i = 1; text1[i]; i++)
		for (j = 1; text2[j]; j++)
			dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (text1[i] == text2[j]) });

	int ti = i - 1, tj = j - 1;
	while (ti > 0 && tj > 0) {
		if (dp[ti][tj] == dp[ti - 1][tj])
			ti--;
		else if (dp[ti][tj] == dp[ti][tj - 1])
			tj--;
		else {
			lcs_text.push_back(text1[ti]);
			ti--; tj--;
		}
	}

	cout << dp[i - 1][j - 1] << "\n";

	for (int i = lcs_text.size() - 1; i >= 0; i--)
		cout << lcs_text[i];
	cout << "\n";

	return 0;
}


/* https://kswims.tistory.com/189 */