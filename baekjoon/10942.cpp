#include	<iostream>
#include	<string.h>
using namespace std;

#define MAX 2000 + 1

int N, M;
int arr[MAX];
bool check[MAX][MAX];

void palindrome() {
	// len 1
	for (int i = 1; i <= N; i++)
		check[i][i] = true;
	// len 2
	for (int i = 1; i <= N - 1; i++)
		if (arr[i] == arr[i + 1])
			check[i][i + 1] = true;
	// len 3 or more
	for (int i = 2; i <= N - 1; i++)
		for (int j = 1; j <= N - i; j++)
			if (arr[j] == arr[i + j] && check[j + 1][i + j - 1] == true)
				check[j][i + j] = true;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	memset(check, false, sizeof(check));
	palindrome();

	cin >> M;
	int s_pos, e_pos;
	while (M--) {
		scanf("%d %d", &s_pos, &e_pos);
		printf("%d\n", check[s_pos][e_pos]);
	}

	return 0;
}