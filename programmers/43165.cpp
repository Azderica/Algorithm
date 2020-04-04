#include	<iostream>
#include	<vector>
using namespace std;

#define MAX 20

vector<int> Numbers;
int visited[MAX];
int answer = 0;
int Target, N;

void dfs(int cnt) {
    if (cnt == N) {
        int res = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i] == 0)
                res += Numbers[i];
            else
                res -= Numbers[i];
        }
        if (res == Target)
            answer++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        visited[cnt] = i;   // 0 is +, 1 is -
        dfs(cnt + 1);
    }
}

int solution(vector<int> numbers, int target) {
    Numbers = numbers;
    N = numbers.size();
    Target = target;

    dfs(0);

    return answer;
}

int main() {
    cout << solution({ 1, 1, 1, 1, 1 }, 3) << "\n";

	return 0;
}