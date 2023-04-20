#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    int val;
    Node* right, *left;

    Node(int val){
        this->val =val;
        right = left = nullptr;
    }
};

struct BST{
    Node* root;

    BST(){root = nullptr;}

private:
    void _preorder(Node* node){
        if(!node) return;
        cout << node->val << " ";
        _preorder(node->left);
        _preorder(node->right);
    }

    Node* _getBalance(vector <int>& v, int l, int r){
        if(l > r) return nullptr;
        int centre = l + (r-l)/2;
        Node* newnode = new Node(v[centre]);
        newnode->left = _getBalance(v, l, centre - 1);
        newnode->right = _getBalance(v, centre + 1, r);
        return newnode;
    }

public:
    void preorder(){
        _preorder(root);
    }

    Node* getBalance(vector <int>& v){
        return _getBalance(v, 0, v.size() - 1);
    }
};

int main(){
    BST bst; int n; cin >> n;
    vector <int> v;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    bst.root = bst.getBalance(v);
    bst.preorder();
}
