#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    string val;
    Node *next;

    Node(string val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size = 0, cnt = 0;
    Node *head, *tail;

    void add(string val){
        Node *newnode = new Node(val);
        if(this->size == 0){
            this->head = newnode;
            this->tail = newnode;
        }
        else{
            newnode->next = this->head;
            this->head = newnode;
        }
        this->size++;
    }

    void del_dupl(){
        Node* cur1 = this->head;
        Node *cur2, *dup;
        while(cur1 && cur1->next){
            cur2 = cur1;
                if(cur1->val == cur2->next->val){
                    dup = cur2->next;
                    cur2->next = cur2->next->next;
                    delete dup;
                }
                else{
                    cur2 = cur2->next;
                    cur1 = cur1->next;
                }

        }
    }
    int get_amount(){
        Node *cur = this->head;
        int cnt = 0;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }

    void print(){
        Node *cur = this->head;
        while(cur){
            cout << cur->val << endl;
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList *L = new LinkedList();
    int n, cnt = 0;
    cin >> n;
    string s;
    while(cin >> s){
        cnt++;
        L->add(s);
        if(cnt == n){
            break;
        }
    }
    L->del_dupl();
    cout << "All in all: " << L->get_amount() << endl;
    cout << "Students:" << endl;
    L->print();
}