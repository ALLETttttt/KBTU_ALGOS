#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll p = 11;
vector <ll> hashes;

ll getHash(string &s){
    ll res = 0, h = 1;
    for(int i = 0; i < s.size(); i++){
        res = (res + (s[i] - 'a' + 1) * h) % mod;
        h = (h * p) % mod;
    }
    return res;
}

void getPref(string &s){
    ll h = 1;
    hashes.resize(s.size());
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * h % mod;
        if(i) hashes[i] = (hashes[i] + hashes[i-1]) % mod;
        h = (h * p) % mod;
    }
}

void RBK(string &s, pair <string, int> &pp, int &maxi){
    if(pp.first.size() > s.size()) return;
    ll smlhash = getHash(pp.first);
    for(int i = 0; i < s.size() - pp.first.size() + 1; i++){
        ll bighash = hashes[i + pp.first.size() - 1];
        if(i) bighash -= hashes[i-1];
        if(bighash < 0) bighash += mod;
        if(i) smlhash = (smlhash * p) % mod;
        if(bighash == smlhash){
            pp.second++;
            maxi = max(maxi, pp.second);
        }
    }
}

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        pair<string, int> p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i].first;
            p[i].second = 0;
        }
        string s; cin >> s;
        getPref(s);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            RBK(s, p[i], maxi);
        }
        cout << maxi << "\n";
        for(int i = 0; i < n; i++){
            if(maxi == p[i].second){
                cout << p[i].first << "\n";
            }
        }
    }
}