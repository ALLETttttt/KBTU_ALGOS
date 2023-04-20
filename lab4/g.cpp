#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
    Node* root;

    BST(){root = nullptr;}

private:
	Node* _insert(Node* cur, int val) {
		if (cur == nullptr) return new Node(val);
		if (cur->val > val) cur->right = _insert(cur->right, val);
		else if (cur->val < val) cur->left = _insert(cur->left, val);
		return cur;
	}

public:
	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (root == nullptr) root = newNode;
	}

	Node* getRoot() {
		return root;
	}

	int getHeight(Node* node, int& d) {
		if (!node) return 0;
		int left = getHeight(node->left, d);
		int right = getHeight(node->right, d);
		d = max(d, left + right + 1);
		return max(left, right) + 1;
	}
};

int main() {
	BST bst; int n; cin >> n;
	while (n--) {int node; cin >> node; bst.insert(node);}
	int d = 0; bst.getHeight(bst.getRoot(), d);
	cout << d;
}