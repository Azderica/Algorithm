#include	<iostream>
#include	<queue>
#include	<string>
#include	<string.h>
using namespace std;

#define MAX 100 + 3

int H, W;
char box[MAX][MAX];
bool visited[MAX][MAX];
bool key[26];
int document;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		// out of size
		if (curY < 0 || curY > H + 1 || curX < 0 || curX > W + 1)
			continue;

		// visited or wall, locked door
		if (visited[curY][curX] || box[curY][curX] == '*' || ('A' <= box[curY][curX] && box[curY][curX] <= 'Z'))
			continue;

		visited[curY][curX] = true;

		// doc
		if (box[curY][curX] == '$') {
			document++;
			box[curY][curX] = '.';
		}

		// if find key
		if ('a' <= box[curY][curX] && box[curY][curX] <= 'z') {
			char door = (char)toupper(box[curY][curX]);
			box[curY][curX] = '.';

			if (key[(int)door - (int)'A'] == false) {
				key[(int)door - (int)'A'] = true;
				// open the door
				for (int i = 1; i <= H; i++)
					for (int j = 1; j <= W; j++)
						if (box[i][j] == door)
							box[i][j] = '.';

				// check one more time
				memset(visited, false, sizeof(visited));
				while (!q.empty())
					q.pop();
				q.push({ curY, curX });
				continue;
			}
		}

		// dir 4
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			q.push({ nextY, nextX });
		}
	}
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		// init
		memset(key, false, sizeof(key));
		memset(visited, false, sizeof(visited));
		
		// input
		char line[MAX];
		cin >> H >> W;
		for (int i = 0; i <= W + 1; i++) {
			box[0][i] = '.';
			box[H + 1][i] = '.';
		}
		for (int i = 1; i <= H; i++) {
			scanf("%s", line);
			box[i][0] = '.';
			box[i][W + 1] = '.';
			for (int j = 1; j <= W; j++)
				box[i][j] = line[j - 1];
		}
		
		string alphabet;
		cin >> alphabet;

		for (int j = 0; alphabet[j] != '0' && j < alphabet.length(); j++) {
			key[(int)alphabet[j] - (int)'a'] = true;
			for (int y = 1; y <= H; y++)
				for (int x = 1; x <= W; x++)
					if (box[y][x] == (char)toupper(alphabet[j]))
						box[y][x] = '.';
		}

		document = 0;
		bfs(0, 0);
		cout << document << "\n";
	}
}