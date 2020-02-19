#include	<iostream>
#include	<cstdio>
#include	<cstdlib>
#include	<string>
#include	<map>
#include	<vector>
using namespace std;

int main() {
	int N, M;
	char temp[21];
	map<string, int> pokemon_1;
	vector<string> pokemon_2;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		string name = temp;

		pokemon_1.insert(pair<string, int>(name, i));
		pokemon_2.push_back(name);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", temp);
		if (temp[0] >= 'A' && temp[0] <= 'Z') {
			string name = temp;
			printf("%d\n", pokemon_1[name] + 1);
		}
		else {
			cout << pokemon_2[atoi(temp) - 1] << "\n";
		}
	}

	return 0;
}