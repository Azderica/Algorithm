#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

#define MAX 200000 + 1

struct ball {
	int color, size, idx;
};

vector<ball> Ball;
int accul, colorSum[MAX], ans[MAX];
int N;

bool comp(const ball a, const ball b) {
	return a.size < b.size;
}

int main() {
	// input
	cin >> N;
	Ball.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Ball[i].color, &Ball[i].size);
		Ball[i].idx = i;
	}

	// solution
	sort(Ball.begin(), Ball.end(), comp);
	for (int i = 0, j = 0; i < N; i++) {
		for (; Ball[i].size > Ball[j].size; j++) {
			accul += Ball[j].size;
			colorSum[Ball[j].color] += Ball[j].size;
		}
		ans[Ball[i].idx] = accul - colorSum[Ball[i].color];
	}

	// output
	for (int i = 0; i < N; i++)
		cout << ans[i] << "\n";

	return 0;
}