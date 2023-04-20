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
    Node* root;

    BST(){root = nullptr;}

private:
    void _inorder(Node* node){
        if(node == nullptr) return;
        _inorder(node->right);
        cout << node->val << " ";
        _inorder(node->left);
    }

    Node* _insert(Node* cur, int val){
        if(cur == nullptr) return new Node(val);
        if(cur->val > val) cur->left = _insert(cur->left, val);
        else if(cur->val < val) cur->right = _insert(cur->right, val);
        return cur;
    }

public:
    void inorder(){
        _inorder(root);
    }

    Node* getRoot(){
        return root;
    }

    void insert(int val){
        Node* newnode = _insert(root, val);
        if(root == nullptr) root = newnode;
    }

    void getSumTree(Node *cur, int& sum){
        if(cur == nullptr) return;
        getSumTree(cur->right, sum);
        sum += cur->val;
        cur->val = sum;
        getSumTree(cur->left, sum);
    }
};

int main(){
    BST bst; int n, sum = 0; cin >> n;
    while(n--){int x; cin >> x; bst.insert(x);}
    bst.getSumTree(bst.getRoot(), sum);
    bst.inorder();
}