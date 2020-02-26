#include	<iostream>

using namespace std;

#define N_MAX 100000 + 1

int n;
int in_order[N_MAX];
int post_order[N_MAX];

void print_pre_order(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e)
		return;
	int r = post_order[post_e];
	printf("%d ", r);
	print_pre_order(in_s, in_order[r] - 1, post_s, post_s + in_order[r] - in_s - 1);
	print_pre_order(in_order[r] + 1, in_e, post_s + in_order[r] - in_s, post_e - 1);
}

int main() {
	int x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		in_order[x] = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &post_order[i]);

	print_pre_order(0, n - 1, 0, n - 1);
	cout << "\n";

	return 0;
}