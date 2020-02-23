#include	<iostream>
#include	<string.h>

using namespace std;

#define MAX 21

int main(void) {
	int M, x;
	char instr[10];
	bool S[MAX] = { false, };

	cin >> M;
	for (int m = 0; m < M; m++) {
		scanf("%s %d", instr, &x);

		if (strcmp(instr, "add") == 0) {
			if (!S[x])
				S[x] = true;
		}
		else if (strcmp(instr, "remove") == 0) {
			if (S[x])
				S[x] = false;
		}
		else if (strcmp(instr, "check") == 0) {
			if (S[x])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (strcmp(instr, "toggle") == 0) {
			if (S[x])
				S[x] = false;
			else
				S[x] = true;
		}
		else if (strcmp(instr, "all") == 0) {
			for (int i = 1; i < MAX; i++)
				S[i] = true;
		}
		else if (strcmp(instr, "empty") == 0) {
			for (int i = 1; i < MAX; i++)
				S[i] = false;
		}
	}

	return 0;
}