#include	<iostream>
#include	<queue>
#include	<vector>
#include	<set>
#include	<string.h>
using namespace std;

#define MAX 1000

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int N, M;
int miro[MAX][MAX];
int Area_Num[MAX][MAX];
int Zero_Area_Num = 0;
int ans[MAX][MAX];
bool visited[MAX][MAX];
vector<int> Zero_Area_Size;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	int cnt = 1;
	Area_Num[y][x] = Zero_Area_Num;
	visited[y][x] = true;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
				if (miro[nextY][nextX] == 0 && !visited[nextY][nextX]) {
					visited[nextY][nextX] = true;
					Area_Num[nextY][nextX] = Zero_Area_Num;
					q.push({ nextY, nextX });
					cnt++;
				}
			}
		}
	}
	Zero_Area_Size.push_back(cnt);
}

int main() {
	char line[MAX + 1];

	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", line);
		for (int j = 0; j < M; j++)
			miro[i][j] = line[j] - '0';
	}
	memset(Area_Num, -1, sizeof(Area_Num));

	// solution
	for (int i = 0; i < N; i++) {
		for(int j=0; j<M; j++)
			if (miro[i][j] == 0 && !visited[i][j]) {
				bfs(i, j);
				Zero_Area_Num++;
			}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (miro[i][j] == 1) {
				set<int> Search;
				for (int k = 0; k < 4; k++) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
						if (miro[nextY][nextX] == 0) {
							// no find
							if (Search.find(Area_Num[nextY][nextX]) == Search.end()) {
								Search.insert(Area_Num[nextY][nextX]);
								ans[i][j] += Zero_Area_Size[Area_Num[nextY][nextX]];
							}
						}
					}
				}
				ans[i][j] = (ans[i][j] + 1) % 10;
			}
		}
	}

	// output
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << ans[i][j];
		cout << "\n";
	}

	return 0;
}