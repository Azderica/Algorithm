#include	<iostream>
#include	<string.h>
using namespace std;

int main(void) {
	char line[6];

	scanf("%s", line);
	while (strcmp(line, "0")) {
		int len = strlen(line) - 1;
		bool flag = true;

		for (int i = 0; i <= len / 2; i++) {
			if (line[i] != line[len - i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";

		scanf("%s", line);
	}


	return 0;
}