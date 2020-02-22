#include	<iostream>
#include	<string>
#include	<stack>
using namespace std;

int main() {
	string str;
	string result;
	stack<char> s;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z')
			result += str[i];
		else {
			switch (str[i])
			{
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case '+':
			case '-':
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case ')':
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result << "\n";
	return 0;
}