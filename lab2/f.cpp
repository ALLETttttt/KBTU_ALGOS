#include <iostream>
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

    void addAtHead(int val){
        Node *newnode = new Node(val);
        if (this->size == 0){
            this->head = newnode;
            this->tail = newnode;
        }
        else{
            newnode-> next = this->head;
            this-> head = newnode;
        }
        this->size++;
    }

    void addAtTail(int val){
        Node *newnode = new Node(val);
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

    void insert(int index, int val){
        if(index < 0 || index > this->size){
            return ;
        }
        if(index == 0){
            this->addAtHead(val);
        }
        else if(index == this->size){
            this->addAtTail(val);
        }
        else{
            Node *newnode = new Node(val);
            Node *cur = this->head;
            for(int i = 0; i < index-1; i++){
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            this->size++;
        }
    }

    void print(){
        Node *cur = this->head;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList *L = new LinkedList();
    int n, data, index;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        L->addAtTail(x);
    }
    cin >> data;
    cin >> index;
    L->insert(index, data);
    L->print();
}