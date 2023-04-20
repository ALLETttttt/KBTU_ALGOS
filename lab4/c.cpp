#include <iostream>
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
    Node* _insert(Node* cur, int val){
        if(cur == nullptr) return new Node(val);
        if(cur->val > val) cur->left = _insert(cur->left, val);
        else cur->right = _insert(cur->right, val);
        return cur;
    }

    Node* _search(Node* cur, int target){
        if(cur == nullptr) return nullptr;
        if(cur->val == target) return cur;
        else if(cur->val > target) return _search(cur->left, target);
        else return _search(cur->right, target);
    }

    void _preorder(Node* node){
        if(node == nullptr) return;
        cout << node->val << ' ';
        _preorder(node->left);
        _preorder(node->right);
    }

public:
    void insert(int val){
        Node* newnode = _insert(root, val);
        if(root == nullptr) root = newnode;
    }

    void getSubtree(int val){
        Node* cur = root;
        cur = _search(root, val);
        _preorder(cur);
    }
};

int main(){
    BST bst;
    int n, k; cin >> n;
    for(int i = 0; i < n; i++){int x; cin >> x; bst.insert(x);}
    cin >> k; bst.getSubtree(k);
}