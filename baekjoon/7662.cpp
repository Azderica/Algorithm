#include	<iostream>
#include	<set>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k, num;
		char op;
		multiset<int> d_p_q;

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> op >> num;

			if (op == 'I')
				d_p_q.insert(num);
			else if(op == 'D' && d_p_q.size() > 0) {
				if (num == -1)
					d_p_q.erase(d_p_q.begin());
				else {
					auto pos = d_p_q.end();
					pos--;
					d_p_q.erase(pos);
				}
			}
		}

		if (d_p_q.size() == 0) 
			cout << "EMPTY\n";
		else {
			auto pos = d_p_q.end();
			pos--;
			cout << *pos << " " << *d_p_q.begin() << "\n";
		}
	}

	return 0;
}