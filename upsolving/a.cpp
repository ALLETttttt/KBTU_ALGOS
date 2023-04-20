#include <iostream>
#include <vector>
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
    Node* _insert(Node *cur, int val){
        if(!cur) return new Node(val);
        if(cur->val < val) cur->right = _insert(cur->right, val);
        else cur->left = _insert(cur->left, val);
        return cur;
    }

public:
    Node* getRoot(){
        return root;
    }

    void insert(int val){
        Node* newnode = _insert(root, val);
        if(!root) root = newnode;
    }

    void getTriangle(vector <int> &v, Node* cur){
        if(!cur) return;
        Node* left = cur->left;
        Node* right = cur->right;
        int i = 0;
        while(left && right){
            v[i++]++;
            left = left->left;
            right = right->right;
        }
        getTriangle(v, cur->left);
        getTriangle(v, cur->right);
    }
};

int main(){
    BST bst;
    int n; cin >> n;
    for(int i = 0; i < n; i++){int x; cin >> x; bst.insert(x);}
    vector <int> v(n-1);
    bst.getTriangle(v, bst.getRoot());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}