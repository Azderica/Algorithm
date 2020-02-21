#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

struct time {
	int start;
	int end;
};

// 종료시점 우선, 그 후 시작시점
bool comp(const time& a, const time& b) {	
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main() {
	int N;
	int ans = 0, pos = 0;

	cin >> N;
	vector<time> meeting(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &meeting[i].start, &meeting[i].end);
	}

	sort(meeting.begin(), meeting.end(), comp);

	// 끝까지 돌면서 빨리 끝내는거보다 시작점이 늦은 경우
	for (int i = 0; i < meeting.size(); i++) {	
		if (pos <= meeting[i].start) {	 
			pos = meeting[i].end;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}