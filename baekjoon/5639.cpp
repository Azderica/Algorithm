#include	<iostream>
#include	<algorithm>
using namespace std;

typedef struct Node {
	int key;
	Node* left;
	Node* right;
	Node(const int& _key) : key(_key), left(NULL), right(NULL) { }
	void setLeft(Node* leftTree) { left = leftTree; }
	void setRight(Node* rightTree) { right = rightTree; }
};

Node* insert(Node* root, Node* cur) {
	if (root == NULL)
		return cur;
	if (cur->key < root->key)
		root->setLeft(insert(root->left, cur));
	else
		root->setRight(insert(root->right, cur));
	return root;
}

void postorder(Node* cur) {
	if (cur) {
		postorder(cur->left);
		postorder(cur->right);
		cout << cur->key << "\n";
	}
}

int main() {
	int num;
	Node* root = NULL;

	while (scanf("%d", &num) != -1) {
		root = insert(root, new Node(num));
	}

	postorder(root);

	return 0;
}