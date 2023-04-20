#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int p = 11;
vector <ll> hashes;
vector <bool> saw;

ll getHash(string s){
    ll h = 1, res = 0;
    for(int i = 0; i < s.size(); i++){
        res = (res + (s[i] - 'a' + 1) * h) % mod;
        h = (h * p) % mod;
    }
    return res;
}

void getPref(string s){
    hashes.resize(s.size()); ll h = 1;
    saw.resize(s.size());
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * h % mod;
        if(i) hashes[i] = (hashes[i] + hashes[i-1]) % mod;
        h = (p * h) % mod;
    }
}

void RBK(string s, string pattern){
    ll smlhash = getHash(pattern);
    for(int i = 0; i < s.size() - pattern.size() + 1; i++){
        ll bighash = hashes[i + pattern.size() - 1];
        if(i) bighash -= hashes[i-1];
        if(bighash < 0) bighash += mod;
        if(i) smlhash = (smlhash * p) % mod;
        if(smlhash == bighash){
            for(int pll = i; pll < i + pattern.size(); pll++){
                saw[pll] = true;
            }
        }
    }
}

int main(){
    string s; cin >> s;
    getPref(s);
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string text; cin >> text;
        RBK(s, text);
    }

    for(int i = 0; i < s.size(); i++){
        if(!saw[i]){
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES";
}