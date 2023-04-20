#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix;

vector <int> getPrefix(string s){
    prefix.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = prefix[i - 1];
        while(j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if(s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

bool KMP_GOI_KRCH(string s, string pattern, int point){
    string join = pattern + '#' + s; int cnt = 0;
    vector <int> final = getPrefix(join);
    for(int i = pattern.size() + 1; i < join.size(); i++){
        if(final[i] == pattern.size()){
            cnt++;
            if(cnt == point) return true;
        }
    }
    return false;
}


int main(){
    string s, pattern; int n;
    cin >> s >> n >> pattern;
    if(KMP_GOI_KRCH(pattern, s, n)) cout << "YES";
    else cout << "NO";
}