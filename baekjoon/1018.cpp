#include	<iostream>
using namespace std;

#define MAX 50

int get_min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main(void) {
	int N, M;
	char map[MAX][MAX];
	int min = MAX * MAX;

	int count_1, count_2;	// check min


	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);


	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++) {
			count_1 = 0;
			count_2 = 0;
			for (int map_i = i; map_i < i + 8; map_i++)
				for (int map_j = j; map_j < j + 8; map_j++) {
					if ((map_i + map_j) % 2 == 0) {
						if (map[map_i][map_j] == 'B')
							count_1++;
						else
							count_2++;
					}
					else {
						if (map[map_i][map_j] == 'B')
							count_2++;
						else
							count_1++;
					}
				}
			if (get_min(count_1, count_2) < min)
				min = get_min(count_1, count_2);
		}

	cout << min << endl;

	return 0;
}