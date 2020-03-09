#include	<iostream>
#include	<algorithm>
using namespace std;

#define MAX 1000000 + 1
#define INF 999999999

int N, M;
bool button[10] = { false, };
int button_count = 0;

// check num is available
bool check_state(int num) {
	if (num == 0) {
		if (button[0] == false)
			return true;
		else
			return false;
	}
	while (num) {
		if (button[(num % 10)] == true)
			return false;
		num /= 10;
	}
	return true;
}

// num -> channel
int getButtonCount() {
	int count = INF;
	int similar = 0;
	for (int i = 0; i < MAX; i++) {
		if (check_state(i)) {
			if (count > abs(i - N)) {
				count = abs(i - N);
				similar = i;
			}
		}
	}

	if (similar == 0)		// if 0, length is 0
		count++;
	else {					// else, get length through loop
		while (similar) {
			similar /= 10;
			count++;
		}
	}
	return count;
}

int main() { 
	// input
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		button[num] = true;
	}

	// (100 -> channel) or (num -> channel)
	button_count = min(abs(N - 100), getButtonCount());

	cout << button_count << "\n";

	return 0;
}