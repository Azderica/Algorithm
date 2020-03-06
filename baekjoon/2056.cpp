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

//���� ���� �����̴�.

//�־��� �Է��� �̿��� DAG�� �����, �� �۾����� Indegree ���� ���Ѵ�.
//�� �۾��鿡 �ҿ� �Ǵ� �ð��� �����Ѵ�.

//ó���� Indegree�� 0�� �������� queue�� push�� �� ���� ������ �����Ѵ�.
//
//������ ���� �ִµ�, queue���� pop�� �۾��� ����Ǿ� ����� �۾��� ������ ����
//�ҿ�Ǵ� �ð��� �ִ� ���� �ǵ��� �ؾ��Ѵ�.
//��, 'ó������ ���� �۾������� ������ ���� �ҿ�Ǵ� �ð� + ���� �۾� �ϳ��� ������ ���� �ʿ��� �ð�'
//���� �ִ밡 �Ǿ�� �Ѵ�.

//���� ��� �۾� A�� �����ϱ� ���� B�� C�� �����ؾ� �Ѵٰ� ���� ��,
//MAX(ó������ B���� �����ϴµ� �ɸ� �ð�, ó������ C���� �����ϴµ� �ɸ� �ð�) + A�� �����ϴµ� �ʿ��� �ð�
//�̷��� �� �־�� ó������ A���� �����ϴµ� �ɸ��� �ð��� ���� �� �ִٴ� ���̴�.
//������ B�� C �� �� ������ A�� ������ �� �ֱ� �����̴�.
//
//�迭1: �� �۾��� �ϳ��� �ҿ� �ð��� ����
//�迭2 : �� �۾��� ������ ���� �ʿ��� ���� �ҿ� �ð��� ����(�迭 1�� �̿��� ���Ѵ�)
//�ùٸ� ���� ���ϱ� ���� ���� ���� �� �迭�� �̿��Ѵ�.
//
//�̷� ������� �� �۾������ �����ϴ� �� �ɸ��� �ð����� ���ϰ�(�迭2), �׵� �� ���� ū ���� ������ �ȴ�.
//��ó: https://it-earth.tistory.com/111 [����� �������� ���ι�]