#include <bits/stdc++.h>
  
using namespace std;

struct node{
	string word;
	node* next;
	node* prev;
	node(string w){
		word = w;
		next = NULL;
		prev = NULL;
	}
};

node* head = NULL;
node* tail = NULL;
void add_front(string s){
			node* newnode = new node(s);
			if(not tail){head = newnode;tail = newnode;}
			else{
				head->prev = newnode;
				newnode->next = head;
				head = newnode;
			}
}

void add_back(string s){
			node* newnode = new node(s);
			if(not head){tail = newnode;head = newnode;}
			else{
				newnode->prev = tail;
				tail->next = newnode;
				tail = newnode;
			}
}

void erase_front(){
    
        if (head->next != NULL) {
            head->next->prev = NULL;
        }
        node* next = head->next;
        free(head);
        head = next;
    		
}

void erase_back(){
    
        if (tail->prev != NULL) {
            tail->prev->next = NULL;
        }
        node* prev = tail->prev;
        tail->prev = NULL;
        free(tail);
        tail = prev;
				
    
}

string front(){
	return head->word;
}

string back(){
	return tail->word;
}

void clear(){
	node* tmp = head;
	while(head){
		tmp = head;
		head = head->next;
		free(tmp);
	}	
}

bool empty(){
	return head == NULL or tail == NULL;
}



int main()
{
	
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
		if(s == "empty")cout << empty();
   	}
    return 0;
}