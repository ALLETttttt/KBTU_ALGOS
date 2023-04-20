#include <bits/stdc++.h>
using namespace std;
#define ll long long
string bin_reps(ll n){
    string s = "";
    while(n != 0){
        if(n % 2 == 0){
            s = '0' + s;
        }
        else{
            s = '1' + s;
        }
        n /= 2; 
    }
    return s;
}
 
bool isGood(string s){
    stack <char> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()) st.push(s[i]);
        else if(st.top() == '1' && s[i] == '0') st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) return true;
    return false;
}


int main(){
    ll n; cin >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(isGood(bin_reps(x))) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}