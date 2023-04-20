#include <iostream>
using namespace std;

struct Node{
  int val;
  int cnt;
  Node *right, *left;

  Node(int val){
    this->val = val;
    this->cnt = 0;
    right = left = nullptr;
  }
};

struct BST{
  Node* root;

  BST(){root = nullptr;}

private:
  int rightmost(Node* cur){
    if(!cur) return -1;
    if(!cur->right) return cur->val;
    return rightmost(cur->right);
  }

  Node* _insert(Node* cur, int val){
    if(!cur){
      Node* newnode = new Node(val);
      newnode->cnt++;
      return newnode;
    }
    if(cur->val > val) cur->left = _insert(cur->left, val);
    else if(cur->val < val) cur->right = _insert(cur->right, val);
    return cur;
  }

  Node* _search(Node* cur, int target){
    if(!cur) return nullptr;
    if(cur->val == target) return cur;
    else{
      Node* found = _search(cur->left, target);
      if(!found){
        found = _search(cur->right, target);
      }
      return found;
    }
    return nullptr;
  }

  Node* _remove(Node* cur, int target){
    if(!cur) return nullptr;
    if(cur->val == target){
      if(!cur->left && !cur->right){
        delete cur;
        return nullptr;
      }
      else if(!cur->right && cur->left){
        Node* now = cur->left;
        delete cur;
        return now;
      }
      else if(cur->right && !cur->left){
        Node* now = cur->right;
        delete cur;
        return now;
      }
      else if(cur->right && cur->left){
        cur->val = rightmost(cur->left);
        cur->left = _remove(cur->left, target);
      }
    }
    else if(cur->val > target){
      cur->left = _remove(cur->left, target);
      return cur;
    }
    else if(cur->val < target){
      cur->right = _remove(cur->right, target);
      return cur;
    }
    return cur;
  }

  int _print(int val){
    Node* cur = _search(root, val);
    if(cur) return cur->cnt;
    return 0;
  }

public:
  void insert(int val){
    Node* cur = _search(root, val);
    if(!cur){
      Node* newnode = _insert(root, val);
      if(!root) root = newnode;
    }
    else{
      cur->cnt++;
    }
  }

  void remove(int val){
    Node* cur = _search(root, val);
    if(cur->cnt != 0) cur->cnt--;
    else root = _remove(root, val);
  }

  void print(int val){
    cout << _print(val) << endl;
  }
};

int main(){
  BST bst; int n; cin >> n;
  while(n--){
    string s; int x;
    cin >> s >> x;
    if(s == "insert") bst.insert(x);
    else if(s == "delete") bst.remove(x);
    else if(s == "cnt") bst.print(x);
  }
  return 0;
}