#include <bits/stdc++.h>
using namespace std;

int search(string str, string pattern, int mod = 1e9 + 7, int d = 31){
    int hashedpattern = 0, hashedstr = 0, h = 1, cnt = 0;
    for(int i = 0; i < pattern.size() - 1; i++){
        h = (h * d) % mod;
    }
    for(int i = 0; i < pattern.size(); i++){
        hashedpattern = (hashedpattern * d + pattern[i]) % mod;
        hashedstr = (hashedstr * d + str[i]) % mod;
    }
    for(int i = 0; i <= str.size() - pattern.size(); i++){
        if(hashedpattern == hashedstr){cnt++;}
        if(i < str.size() - pattern.size()){
            hashedstr = (d * (hashedstr - str[i] * h) + str[i + pattern.size()]) % mod;
            if(hashedstr < 0) hashedstr += mod;
        }
    }
    if(cnt == 0){
        return 1;
    }
    return cnt;
}


int main(){
    string s; cin >> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        cout << search(s, s.substr(x, y - x + 1)) << endl;
    }
}