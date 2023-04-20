#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size = 0;
    ListNode *head, *tail;

    void add(int val){
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

    void deletee(){
        ListNode *cur = this->head;
        while(cur && cur->next){
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            free(temp);
        }
    }

    void print(){
        ListNode *cur = this->head;
        while(cur){
            cout << cur->val << ' ';
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList *L = new LinkedList();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        L->add(k);
    }
    L->deletee();
    L->print();
}