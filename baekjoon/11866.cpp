#include	<iostream>
#include	<queue>

using namespace std;

int main(void) {
	int N, K;
	queue<int> people;

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		people.push(i);

	cout << "<";
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < K - 1; j++) {
			people.push(people.front());
			people.pop();
		}
		cout << people.front() << ", ";
		people.pop();
	}
	cout << people.front() << ">\n";

	return 0;
}