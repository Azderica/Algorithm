#include	<iostream>
#include    <string>
#include    <vector>
using namespace std;

typedef long long ll;
#define MAX 80 + 1

ll row[MAX];
ll col[MAX];

ll solution(int N) {
    ll answer = 0;

    row[0] = 0; col[0] = 0;
    row[1] = 1; col[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            row[i] = row[i - 1];
            col[i] = row[i - 1] + col[i - 1];
        }
        else {
            col[i] = col[i - 1];
            row[i] = row[i - 1] + col[i - 1];
        }
    }

    answer = (row[N] + col[N]) * 2;

    return answer;
}

int main() {
    cout << solution(5) << "\n";
    cout << solution(6) << "\n";

    return 0;
}