#include	<iostream>

using namespace std;

int main(void) {
	int N, M, B;
	int** map;

	cin >> N >> M >> B;
	map = new int* [N];
	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	return 0;
}