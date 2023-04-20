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

bool SOL_KMP_GOI(string s, string t){
    string join = t + '$' + s;
    vector <int> res = getPref(join);
    for(int i = t.size() + 1; i < join.size(); i++){
        if(res[i] == t.size()){
            return true;
        }
    }
    return false;
}


int main(){
    string s, t, addedstr; int counter = 1;
    cin >> s >> t;
    addedstr = s;
    while(addedstr.size() < t.size()){addedstr += s; counter++;}
    if(SOL_KMP_GOI(addedstr, t)) cout << counter;
    else if(SOL_KMP_GOI(addedstr + s, t)) cout << counter + 1;
    else cout << -1;
}