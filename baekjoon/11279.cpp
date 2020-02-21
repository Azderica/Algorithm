#include	<iostream>
using namespace std;

#define MAX 100001

class MaxHeap {
	int node[MAX];
	int size;
public:
	MaxHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX - 1; }
	int getParent(int i) { return node[i / 2]; }
	int getLeft(int i) { return node[i * 2]; }
	int getRight(int i) { return node[i * 2 + 1]; }
	void insert(int key) {
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key > getParent(i)) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i] = key;
	}
	int remove() {
		if (isEmpty()) return 0;
		int removeitem = node[1];
		int last = node[size--];
		int parent = 1;
		int child = 2;
		while(child <= size){
			if (child < size && getLeft(parent) < getRight(parent))
				child++;
			if (last >= node[child])
				break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return removeitem;
	}
};

int main() {
	int N, num;
	MaxHeap heap;

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num > 0) {	// positive
			heap.insert(num);
		}
		else {		// 0
			cout << heap.remove() << "\n";
		}
	}


	return 0;
}