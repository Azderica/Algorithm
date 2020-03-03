#include	<iostream>
#include	<algorithm>
using namespace std;

int arr_max[3], arr_min[3];
int tmp_max[3], tmp_min[3];

int main() {
	int n;
	cin >> n;
	int arr[3];

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		arr_max[0] = max(tmp_max[0], tmp_max[1]) + arr[0];
		arr_max[1] = max(max(tmp_max[0], tmp_max[1]), tmp_max[2]) + arr[1];
		arr_max[2] = max(tmp_max[1], tmp_max[2]) + arr[2];

		arr_min[0] = min(tmp_min[0], tmp_min[1]) + arr[0];
		arr_min[1] = min(min(tmp_min[0], tmp_min[1]), tmp_min[2]) + arr[1];
		arr_min[2] = min(tmp_min[1], tmp_min[2]) + arr[2];

		tmp_max[0] = arr_max[0];	tmp_max[1] = arr_max[1];	tmp_max[2] = arr_max[2];
		tmp_min[0] = arr_min[0];	tmp_min[1] = arr_min[1];	tmp_min[2] = arr_min[2];
	}

	cout << max(max(arr_max[0], arr_max[1]), arr_max[2]) << " ";
	cout << min(min(arr_min[0], arr_min[1]), arr_min[2]) << "\n";


	return 0;
}