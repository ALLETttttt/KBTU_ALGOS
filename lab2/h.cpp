#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if(p == 0){
        node->next = head;
        head = node;
    }else{
        Node* tmp = head;
        while(--p > 0){
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
    }

    return head;

}
 
Node* remove(Node* head, int p){
    /* write your code here */
    Node* tmp1 = head;
    if(p == 0){
        head = tmp1->next;
        free(tmp1);
    }else{
        for(int i = 0; i < p-1; i++)tmp1 = tmp1->next;
        Node* tmp2 = tmp1->next;
        tmp1->next = tmp2->next;
        free(tmp2);
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    if(p1 == p2)return head;
    Node* cur = head;
    int a = 0, i = 0;
    while(true){
        if(i == p1){a = cur->val;break;}
        i++;cur = cur->next;
    }
    head = remove(head, p1);
    head = insert(head, new Node(a), p2);

    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp; 
    }

    return prev;
}
 
void print(Node* head){
    /* write your code here */
    for(Node* cur = head; cur != NULL; cur = cur->next){
        cout << cur->val << ' ';
    }cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    
//   head                tail
//    ↓                   ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘

//           head        tail
//            ↓            ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘


//      tail  head
//        ↓   ↓
// ┌→ 1 → 3 → 5 → 7  →  9 → 11 ─┐
// └────────────────────────────┘

//       tail  head
//        ↓    ↓
// ┌→ 1 → 3    5 → 7 -> 9 → 11 ─┐
// └────────────────────────────┘
            Node *tail = head;
            while(tail->next)tail = tail->next;
            tail->next = head;
            for(int i = 1; i < x; i++)head = head->next;
            tail = head;
            head = head->next;
            tail->next = NULL;
            return head;
}
 

Node* cyclic_right(Node* head, int x){

//    head                tail
//    ↓                   ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘

//                head    tail
//                ↓       ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘


//                tail  head
//                ↓     ↓
// ┌→ 1 → 3 → 5 → 7  →  9 → 11 ─┐
// └────────────────────────────┘

//                tail  head
//                ↓     ↓
// ┌→ 1 → 3 → 5 → 7     9 → 11 ─┐
// └────────────────────────────┘


Node *tail = head;
int sz = 0;
while(tail->next){
    sz++;
    tail = tail->next;
}

tail->next = head;
for(int i = 0; i < sz-x; i++){
    head = head->next;
}


tail = head;
head = head->next;
tail->next = NULL;


return head;
}
 
int main(){
    Node* head = NULL;
    int command;
    // head = insert(head, new Node(0), 0);
    // head = insert(head, new Node(1), 1);
    // head = insert(head, new Node(2), 2);

    // print(head);
    while (cin >> command)
    {
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
} 
