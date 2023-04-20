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

    void print(int k){
        ListNode *cur1 = this->head;
        ListNode *cur2 = this->head;
        for(int i = 0; i < k; i++){
            cur1 = cur1->next;
        }
        for(int i = k; i < this->size; i++){
            cout << cur1->val << " ";
            cur1 = cur1->next;
        }
        for(int i = 0; i < k; i++){
            cout << cur2->val << " ";
            cur2 = cur2->next;
        }
    }
};

int main(){
    LinkedList *L = new LinkedList();
    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        L->add(s);
    }
    L->print(k);    
}