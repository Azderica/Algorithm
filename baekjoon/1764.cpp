#include	<iostream>
#include	<algorithm>
#include	<string>
#include	<vector>

using namespace std;

int main() {
	int N, M;
	char temp[21];
	vector<string> v_1;
	vector<string> v_2;

	cin >> N >> M;
	v_1.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		string str = temp;

		v_1.push_back(str);
	}
	sort(v_1.begin(), v_1.end());

	for (int i = 0; i < M; i++) {
		scanf("%s", temp);
		string str = temp;

		if(binary_search(v_1.begin(), v_1.end(), str)) {
			v_2.push_back(str);
		}
	}
	sort(v_2.begin(), v_2.end());

	printf("%d\n", v_2.size());
	for (int i = 0; i < v_2.size(); i++) {
		printf("%s\n", v_2[i].c_str());
	}

	return 0;
}