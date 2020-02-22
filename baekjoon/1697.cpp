#include	<iostream>
#include	<queue>
using namespace std;

#define MAX 100001

int main() {
	int N, K;
	bool visitied[MAX] = { false, };

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(pair<int, int>(N, 0));

	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;

		if (pos == K)
			break;

		q.pop();

		visitied[pos] = true;

		if (pos - 1 >= 0 && !visitied[pos - 1])
			q.push(pair<int, int>(pos - 1, time + 1));
		if (pos + 1 < MAX && !visitied[pos + 1])
			q.push(pair<int, int>(pos + 1, time + 1));
		if (pos * 2 < MAX && !visitied[pos * 2])
			q.push(pair<int, int>(pos * 2, time + 1));
	}

	cout << q.front().second << " ";


	return 0;
}