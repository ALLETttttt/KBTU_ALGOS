#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right, *left;

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


public:
    void insert(int val){
        Node* newnode = _insert(root, val);
        if(root == nullptr) root = newnode;
    }
    
    Node* getRoot(){
        return root;
    }

    int getHeight(Node *node){
        if(node == nullptr) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(left, right) + 1;
    }

    void getSumLevel(Node* cur, int lvl, vector <int>& v){
        if(cur == nullptr) return;
        v[lvl] += cur->val;
        getSumLevel(cur->left, lvl + 1, v);
        getSumLevel(cur->right, lvl + 1, v);
    }
};

int main(){
    BST bst;
    int n; cin >> n;
    for(int i = 0; i < n; i++){int x; cin >> x; bst.insert(x);}
    vector <int> v(bst.getHeight(bst.getRoot()));
    bst.getSumLevel(bst.getRoot(), 0, v);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}