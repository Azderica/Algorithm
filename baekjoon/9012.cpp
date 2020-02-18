#include	<iostream>
#include	<stack>
#include	<string>
using namespace std;

bool isVPS(string text) {
	int len = (int)text.length();
	stack<char> str;
	
	for(int i=0; i<len; i++){
		if (text[i] == '(')
			str.push(text[i]);
		else {
			if (!str.empty())
				str.pop();
			else
				return false;
		}
	}
	return str.empty();
}

int main(void) {
	int N;
	char word[51];

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", word);
		if (isVPS(word))
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}