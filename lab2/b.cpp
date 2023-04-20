#include <iostream>
using namespace std;

struct ListNode{
    string val;
    ListNode *next;

    ListNode(string val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size;
    ListNode *head;
    ListNode *tail;

    void add(string val){
        ListNode *newNode = new ListNode(val);
        if(this->size == 0){
            this->head = newNode;
            this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void print(){
        ListNode *cur = this->head;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList *L = new LinkedList();
    LinkedList *L1 = new LinkedList();
    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(i >= 0 && i < k){
            L->add(s);
        }
        else{
            L1->add(s);
        }
    }
    L1->print();
    L->print();    
}