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
    Node* _insert(Node* cur, int val){
        if(!cur) return new Node(val);
        if(cur->val < val) cur->right = _insert(cur->right, val);
        else cur->left = _insert(cur->left, val);
        return cur;
    }

public:
    void insert(int val){
        Node* newnode = _insert(root, val);
        if(!root) root = newnode;
    }

    Node* getRoot(){
        return root;
    }

    unsigned int getLeafCount(Node* node) 
    { 
        if(node == NULL) return 0; 
        if(node->left == NULL && node->right == NULL) return 1;         
        else return getLeafCount(node->left)+ getLeafCount(node->right); 
    } 
};

int main(){
    BST bst;
    int n, cnt = 0; cin >> n;
    for(int i = 0; i < n; i++){int x; cin >> x; bst.insert(x);}
    cout << bst.getLeafCount(bst.getRoot());
}
