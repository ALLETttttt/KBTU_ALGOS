#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int val){
        this-> val = val;
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
    
    int offset(int num){
        ListNode *cur = this->head;
        int index = 0, diff = abs(num-(cur->val));
        for(int i = 0; i < this->size; i++){
            if(diff > abs(num-(cur->val))){
                diff = abs(num-(cur->val));
                index = i;
            }
            cur = cur->next;
        }
        return index;
    }
};

int main(){
    LinkedList *lll = new LinkedList();
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        lll->add(a[i]);
    }
    cin >> k;
    cout << lll->offset(k);
}