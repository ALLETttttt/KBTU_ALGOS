#include <iostream>
#include <stack>
using namespace std;
string backspaces1(string s){
    stack <char> st1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            if(st1.size() != 0){
                st1.pop();
            }
        }
        else{
            st1.push(s[i]);
        }
    }
    string res1 = "";
    while(!st1.empty()){
        res1 += st1.top();
        st1.pop();
    }
    return res1;


}
string backspaces2(string t){
    stack <char> st2;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#'){
            if(st2.size() != 0){
                st2.pop();
            }
        }
        else{
            st2.push(t[i]);
        }
    }
    string res2 = "";
    while(!st2.empty()){
        res2 += st2.top();
        st2.pop();
    }
    return res2;
}


int main(){
    string s, t;
    cin >> s >> t;
    string s1 = backspaces1(s);
    string t1 = backspaces2(t);
    if(s1 == t1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}