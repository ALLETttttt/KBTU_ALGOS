#include <bits/stdc++.h>
using namespace std;
#define ll long long

string hashedRes(string s, int mod = 1e9 + 7, int inc = 11){
    ll p = 1; ll res = 0;
    for(int i = 0; i < s.size(); i++){
        res = (res + ((s[i] - 47) * p) % mod) % mod;
        p = (p * inc) % mod;
    }
    return to_string(res);
}


int main(){
    int n, cnt = 0; cin >> n;
    vector <string> v;
    map <string, string> hashmap;
    for(int i = 0; i < n*2; i++){
        string s; cin >> s;
        v.push_back(s);
        hashmap.insert({s, hashedRes(s)});
    }
    for(auto i : v){
        string str = hashedRes(i);
        if(hashmap.find(str) != hashmap.end()){
            cout << "Hash of string \"" << i << "\" is " << str << "\n";
            cnt++;
        }
        if(cnt == n){break;}
    }
}