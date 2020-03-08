#include	<iostream>
#include	<queue>
using namespace std;

#define MAX 20

int N;
int board[MAX][MAX];
int ans;

// bfs
void shift(int type) {
	queue<int> q;
	switch (type)
	{
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0) {
					// empty
					board[i][idx] = data;
				}
				else if (board[i][idx] == data) {
					// same num
					board[i][idx] *= 2;
					idx++;
				}
				else {
					// different num
					idx++;
					board[i][idx] = data;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = N - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0) {
					// empty
					board[i][idx] = data;
				}
				else if (board[i][idx] == data) {
					// same num
					board[i][idx] *= 2;
					idx--;
				}
				else {
					// different num
					idx--;
					board[i][idx] = data;
				}
			}
		}
		break;
	case 2:
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][j] == 0) {
					// empty
					board[idx][j] = data;
				}
				else if (board[idx][j] == data) {
					// same num
					board[idx][j] *= 2;
					idx++;
				}
				else {
					// different num
					idx++;
					board[idx][j] = data;
				}
			}
		}
		break;
	case 3:
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = N - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[idx][j] == 0) {
					// empty
					board[idx][j] = data;
				}
				else if (board[idx][j] == data) {
					// same num
					board[idx][j] *= 2;
					idx--;
				}
				else {
					// different num
					idx--;
					board[idx][j] = data;
				}
			}
		}
		break;
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = max(ans, board[i][j]);
		return;
	}

	int cpyBoard[MAX][MAX];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cpyBoard[i][j] = board[i][j];

	for (int i = 0; i < 4; i++) {
		shift(i);
		dfs(cnt + 1);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = cpyBoard[i][j];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	dfs(0);

	cout << ans << "\n";

	return 0;
}