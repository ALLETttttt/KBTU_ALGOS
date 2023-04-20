#include <iostream>
#include <vector>
using namespace std;

struct Stack{
	vector <pair<int, int> > v;

	bool isEmpty() {
    	return v.size() == 0;
  	}

	void push(int x){
		if(isEmpty()){
			v.push_back({x, x});
		}
		else{
			v.push_back({x, max(x, v.back().second)});
		}
	}

	void top(){
		cout << v.back().first << "\n";
	}

	void pop(){
		if(!isEmpty()) v.pop_back();
	}

	void getMax(){
		cout << v.back().second << "\n";
	}
};

int main(){
	int n; cin >> n;
	Stack st;
	for(int i = 0; i < n; i++){
		string s; int x; cin >> s;
		if(s == "add"){
			cin >> x;
			st.push(x);
		}
		else if(s == "delete"){
			st.pop();
		}
		else if(s == "getcur"){
			if(st.isEmpty()) cout << "error" << "\n";
			else st.top();
		}
		else if(s == "getmax"){
			if(st.isEmpty()) cout << "error" << "\n";
			else st.getMax();
		}
	}
}