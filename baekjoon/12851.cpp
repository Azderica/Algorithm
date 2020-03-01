#include	<iostream>
#include	<queue>

using namespace std;

#define MAX 100000 + 1

bool visited[MAX];

int main() {
	int n, k;
	int min_time = 0, way_case = 0;
	queue<pair<int, int>> q;

	cin >> n >> k;
	q.push(make_pair(n, 0));
	visited[n] = true;

	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		visited[pos] = true;

		// other
		if (min_time && min_time == time && pos == k)
			way_case++;

		// first 
		if (!min_time && pos == k) {
			min_time = time;
			way_case++;
		}

		if (pos + 1 < MAX && !visited[pos + 1])
			q.push(make_pair(pos + 1, time + 1));
		if (pos - 1 >= 0 && !visited[pos - 1])
			q.push(make_pair(pos - 1, time + 1));
		if (pos * 2 < MAX && !visited[pos * 2])
			q.push(make_pair(pos * 2, time + 1));
	}
	cout << min_time << "\n";
	cout << way_case << "\n";

	return 0;
}