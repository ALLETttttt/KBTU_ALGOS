#include <bits/stdc++.h>
using namespace std;
#define ll long long

int count(string s1, string s2, string pattern, ll mod = 9007199254740881, int d = 31){
    ll hashs1 = 0, hashs2 = 0, hashpattern = 0, h = 1, cnt = 0;
    for(int i = 0; i < pattern.size() - 1; i++){
        h = (h * d) % mod;
    }
    for(int i = 0; i < pattern.size(); i++){
        hashs1 = (hashs1 * d + s1[i]) % mod;
        hashs2 = (hashs2 * d + s2[i]) % mod;
        hashpattern = (hashpattern * d + pattern[i]) % mod;
    }
    ll size = min(s1.size(), s2.size());
    for(int i = 0; i <= size - pattern.size(); i++){
        if(hashpattern == hashs1 && hashpattern == hashs2){
            cnt++;
        }
        if(i < size - pattern.size()){
            hashs1 = (d * (hashs1 - s1[i] * h) + s1[i + pattern.size()]) % mod;
            hashs2 = (d * (hashs2 - s2[i] * h) + s2[i + pattern.size()]) % mod;
            if(hashs1 < 0) hashs1 += mod;
            if(hashs2 < 0) hashs2 += mod;
        }
    }
    return cnt;
}

int main(){
    string s, t, pattern;
    cin >> s >> t >> pattern;
    cout << count(s, t, pattern);
}