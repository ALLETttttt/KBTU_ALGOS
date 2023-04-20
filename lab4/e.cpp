#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *right, *left;

    Node(int val){
        this->val = val;
        right = left = nullptr;
    }
};

struct BST{
    Node *root;

    BST(){root = nullptr;}
private:
    Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		else {
			Node* found = _search(cur->left, target);
			if (found == nullptr) {
				found = _search(cur->right, target);
			}
			return found;
		}
		return nullptr;
	}

public:
    void setRoot(Node *root){
        this->root = root;
    }

    Node* getRoot(){
        return root;
    }

    Node* search(int target){
        return _search(root, target);
    }

    int getHeight(Node* node){
        if(node == nullptr) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(right, left) + 1;
    }

    void getWidth(int lvl, vector <int>& v, Node* cur){
        if(cur == nullptr) return;
        v[lvl]++;
        getWidth(lvl + 1, v, cur->left);
        getWidth(lvl + 1, v, cur->right);
    }
};

int main(){
    BST bst;
    int n; cin >> n; n--;
    bst.setRoot(new Node(1));
    while(n--){
        int x, y, z; cin >> x >> y >> z;
        Node* king = bst.search(x);
        if(z == 0) {
            king->left = new Node(y);
        }
        else {
            king->right = new Node(y);
        }
    }
    vector <int> v(bst.getHeight(bst.getRoot()));
    bst.getWidth(0, v, bst.getRoot());
    sort(v.begin(), v.end());
    cout << v[v.size()-1];
}