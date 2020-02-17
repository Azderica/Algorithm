#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

struct Member {
	int num;
	int age;
	char name[101];
};

bool comp(const Member& a, const Member& b) {
	if (a.age == b.age)
		return a.num < b.num;
	return a.age < b.age;
}


int main(void) {
	int N;
	Member tmp;
	vector<Member> team;

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &tmp.age, &tmp.name);
		getchar();
		tmp.num = i;
		team.push_back(tmp);
	}

	sort(team.begin(), team.end(), comp);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", team[i].age, team[i].name);
	}


	return 0;
}