#include	<iostream>
#include	<string.h>
#include	<stack>
using namespace std;

int main(void) {
	int N;
	char line[10];
	stack<int> my_stack;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", line);
		if (!strcmp(line, "push")) {
			int num;
			scanf("%d", &num);
			my_stack.push(num);
		}
		else if (!strcmp(line, "pop")) {
			if (my_stack.empty())
				cout << "-1\n";
			else {
				cout << my_stack.top() << endl;
				my_stack.pop();
			}
		}
		else if (!strcmp(line, "size")) {
			cout << my_stack.size() << endl;
		}
		else if (!strcmp(line, "empty")) {
			if (my_stack.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!strcmp(line, "top")) {
			if (my_stack.empty())
				cout << "-1\n";
			else {
				cout << my_stack.top() << endl;
			}
		}
		else
			continue;
	}


	return 0;
}