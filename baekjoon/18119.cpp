#include	<iostream>
using namespace std;

int n, m, cur = 0xfffffffff, check, table[10000];
bool isknow[10000];

int main() {
	cin >> n >> m;
	char line[10001];
	for (int i = 0; i < n; i++) {
		scanf("%s", line);
		for (int j = 0; line[j]; j++)
			table[i] |= 1 << (line[j] - 'a');
	}

	int op;
	char key;
	while (m--) {
		int cnt = 0;
		scanf("%d %c", &op, &key);
		if (op == 1)
			cur &= ~(1 << (key - 'a'));
		else
			cur |= (1 << (key - 'a'));

		for (int i = 0; i < n; i++)
			if ((table[i] & cur) == table[i])
				cnt++;
		cout << cnt << "\n";
	}

	return 0;
}