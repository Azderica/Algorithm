#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>
using namespace std;

// topological sort problem
int N;
vector<vector<int>> graph;	// work
vector<int> indegree;		// indegree
vector<int> work;			// time
vector<int> d;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			d[i] = work[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int length = graph[now].size();
		for (int i = 0; i < length; i++) {
			int next = graph[now][i];
			indegree[next]--;
			if (d[next] < d[now] + work[next])
				d[next] = d[now] + work[next];
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	cin >> N;

	graph.resize(N + 1);
	indegree.resize(N + 1);
	work.resize(N + 1);
	d.resize(N + 1);
	
	int cnt, temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &work[i]);
		scanf("%d", &cnt);
		while (cnt--) {
			scanf("%d", &temp);
			graph[temp].push_back(i);
			indegree[i]++;
		}
	}

	bfs();

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, d[i]);
	cout << ans << "\n";

	return 0;
}

//위상 정렬 문제이다.

//주어진 입력을 이용해 DAG를 만들고, 각 작업들의 Indegree 값을 구한다.
//각 작업들에 소요 되는 시간도 저장한다.

//처음에 Indegree가 0인 정점들을 queue에 push한 뒤 위상 정렬을 수행한다.
//
//주의할 점이 있는데, queue에서 pop된 작업과 연결되어 수행될 작업을 끝내기 위해
//소요되는 시간은 최대 값이 되도록 해야한다.
//즉, '처음부터 현재 작업까지를 끝내기 위해 소요되는 시간 + 다음 작업 하나를 끝내기 위해 필요한 시간'
//값이 최대가 되어야 한다.

//예를 들어 작업 A를 수행하기 위해 B와 C를 선행해야 한다고 했을 때,
//MAX(처음부터 B까지 수행하는데 걸린 시간, 처음부터 C까지 수행하는데 걸린 시간) + A를 수행하는데 필요한 시간
//이렇게 해 주어야 처음부터 A까지 수행하는데 걸리는 시간을 구할 수 있다는 것이다.
//어차피 B와 C 둘 다 끝나야 A를 수행할 수 있기 때문이다.
//
//배열1: 각 작업들 하나의 소요 시간을 저장
//배열2 : 각 작업을 끝내기 위해 필요한 누적 소요 시간을 저장(배열 1을 이용해 구한다)
//올바른 답을 구하기 위해 위와 같은 두 배열을 이용한다.
//
//이런 방법으로 각 작업들까지 수행하는 데 걸리는 시간들을 구하고(배열2), 그들 중 가장 큰 값이 정답이 된다.
//출처: https://it-earth.tistory.com/111 [어스케이 아조시의 공부방]