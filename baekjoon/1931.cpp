#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

struct time {
	int start;
	int end;
};

// ������� �켱, �� �� ���۽���
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

	// ������ ���鼭 ���� �����°ź��� �������� ���� ���
	for (int i = 0; i < meeting.size(); i++) {	
		if (pos <= meeting[i].start) {	 
			pos = meeting[i].end;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}