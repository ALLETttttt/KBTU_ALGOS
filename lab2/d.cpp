#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size;
    Node *head, *tail;

    LinkedList(){
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add(int val){
        Node* newnode = new Node(val);
        if(this->size == 0){
            this->head = newnode;
            this->tail = newnode;
        }
        else{
            this->tail->next = newnode;
            this->tail = newnode;
        }
        this->size++;
    }
};


int main(){
    LinkedList L;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        L.add(x);
    }
    Node *cur = L.head;
    map <int, int> mp;
    while(cur){
        mp[cur->val]++;
        cur = cur->next;
    }
    vector <int> v;
    int count = 0;
    for(auto i : mp){
        if(i.second > count) {
            count = i.second;
        }
    }
    for(auto i : mp){
        if(i.second == count) {
            v.push_back(i.first);
        }
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i >= 0; i--){
        cout << v[i] << " ";
    }
    return 0;
}