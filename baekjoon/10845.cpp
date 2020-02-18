#include	<iostream>
#include	<string.h>
#include	<queue>
using namespace std;

int main(void) {
	int N;
	char line[10];
	queue<int> my_queue;

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", line);
		if (!strcmp(line, "push")) {
			int num;
			scanf("%d", &num);
			my_queue.push(num);
		}
		else if (!strcmp(line, "pop")) {
			if (my_queue.empty())
				cout << "-1\n";
			else {
				cout << my_queue.front() << endl;
				my_queue.pop();
			}
		}
		else if (!strcmp(line, "size")) {
			cout << my_queue.size() << endl;
		}
		else if (!strcmp(line, "empty")) {
			if (my_queue.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!strcmp(line, "front")) {
			if (my_queue.empty())
				cout << "-1\n";
			else {
				cout << my_queue.front() << endl;
			}
		}
		else if (!strcmp(line, "back")) {
			if (my_queue.empty())
				cout << "-1\n";
			else {
				cout << my_queue.back() << endl;
			}
		}
		else
			continue;
	}


	return 0;
}