#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

struct Pos {
	int x;
	int y;
};

bool comp(const Pos& a, const Pos& b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(void) {
	int N;
	Pos tmp;
	vector<Pos> dot;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &tmp.x, &tmp.y);
		dot.push_back(tmp);
	}

	sort(dot.begin(), dot.end(), comp);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", dot[i].x, dot[i].y);
	}

	return 0;
}