#include	<iostream>
#include	<string.h>
#include	<deque>
using namespace std;

int main(void) {
	int N;
	char line[20];
	deque<int> my_deque;

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", line);
		if (!strcmp(line, "push_front")) {
			int num;
			scanf("%d", &num);
			my_deque.push_front(num);
		}
		else if (!strcmp(line, "push_back")) {
			int num;
			scanf("%d", &num);
			my_deque.push_back(num);
		}
		else if (!strcmp(line, "pop_front")) {
			if (my_deque.empty())
				cout << "-1\n";
			else {
				cout << my_deque.front() << endl;
				my_deque.pop_front();
			}
		}
		else if (!strcmp(line, "pop_back")) {
			if (my_deque.empty())
				cout << "-1\n";
			else {
				cout << my_deque.back() << endl;
				my_deque.pop_back();
			}
		}
		else if (!strcmp(line, "size")) {
			cout << my_deque.size() << endl;
		}
		else if (!strcmp(line, "empty")) {
			if (my_deque.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!strcmp(line, "front")) {
			if (my_deque.empty())
				cout << "-1\n";
			else {
				cout << my_deque.front() << endl;
			}
		}
		else if (!strcmp(line, "back")) {
			if (my_deque.empty())
				cout << "-1\n";
			else {
				cout << my_deque.back() << endl;
			}
		}
		else
			continue;
	}


	return 0;
}