#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix;

vector <int> getPref(string s){
    prefix.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = prefix[i-1];
        while(j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if(s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}


vector <int> SOL_KMP_GOi(string s, string pattern){
    string join = pattern + '#' + s;
    vector <int> final = getPref(join);
    vector <int> res;
    for(int i = pattern.size() + 1; i < join.size(); i++){
        if(final[i] == pattern.size()){
            res.push_back(i - 2 * pattern.size());
        }
    }
    return res;
}


int main(){
    string s, pattern;
    cin >> s >> pattern;
    auto result = SOL_KMP_GOi(s, pattern);
    cout << result.size() << "\n";
    for(auto i : result){
        cout << i + 1 << " ";
    }
}