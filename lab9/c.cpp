#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix;

vector <int> getPref(string s){
    prefix.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = prefix[i-1];
        while(j > 0 && s[i] != s[j]) j = prefix[j-1];
        if(s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

vector <int> SOL_KMP_GOI(string s, string pattern){
    vector <int> finalRes;
    string join = pattern + '$' + s;
    vector <int> res = getPref(join);
    for(int i = pattern.size() + 1; i < join.size(); i++){
        if(res[i] == pattern.size()){
            finalRes.push_back(i - 2 * pattern.size());
        }
    }
    return finalRes;
}

int main(){
    string s, pattern;
    cin >> s >> pattern;
    pattern += pattern;
    auto finalRes = SOL_KMP_GOI(pattern, s);
    if(finalRes.size() == 0) cout << -1;
    else cout << finalRes[0];
}