#include	<iostream>
#include	<vector>
using namespace std;

#define MAX 50 + 1

vector<int> party[MAX];
bool isTrue[MAX];
bool isKnowTrue[MAX];


int main() {
	int n, m, truth_size;
	int num;

	cin >> n >> m;
	cin >> truth_size;

	// get info who is knowing true
	for (int i = 0; i < truth_size; i++) {
		scanf("%d", &num);
		isKnowTrue[num] = true;
	}

	// get party info
	int partyNum;
	for (int i = 0; i < m; i++) {
		scanf("%d", &partyNum);
		for (int j = 0; j < partyNum; j++) {
			scanf("%d", &num);
			party[i].push_back(num);
		}
	}

	// check when there is no changing
	bool next = true;
	while (next) {
		next = false;
		for (int i = 0; i < m; i++) if (!isTrue[i]) {
			bool flag = false;
			// check someone in party that knows true 
			for (int x : party[i]) if (isKnowTrue[x]) {
				flag = true;
				break;
			}	
			if (flag) {
				isTrue[i] = true;
				next = true;
				// change all memberin party to true man
				for (int x : party[i])	
					isKnowTrue[x] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) if (!isTrue[i])
		ans++;
	cout << ans << "\n";

	return 0;
}