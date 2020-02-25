#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 1001
char text1[MAX], text2[MAX];
int dp[MAX][MAX];	// max length array

int main() {
	int i, j;
	scanf("%s", text1 + 1);
	scanf("%s", text2 + 1);

	for (i = 1; text1[i]; i++)
		for (j = 1; text2[j]; j++)
			dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j],
				dp[i - 1][j - 1] + (text1[i] == text2[j])
				});

	printf("%d\n", dp[i - 1][j - 1]);

	return 0;
}