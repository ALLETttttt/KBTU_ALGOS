#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix;

vector <int> getPref(string s){
    prefix.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = prefix[i - 1];
        while(j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if(s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

int main(){
    string s; cin >> s;
    s[0] = tolower(s[0]);
    int n, maxpref = 0; cin >> n;
    vector <pair<string, int> > strandpref;  
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        str[0] = tolower(str[0]);
        string join = str + s;
        vector <int> pref = getPref(join);
        maxpref = max(maxpref, pref.back());
        strandpref.push_back({str, pref.back()});
    }
    vector <string> result;
    for(auto i : strandpref){
        if(i.second == maxpref && maxpref != 0){
            result.push_back(i.first);
        }
    }
    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++){
        result[i][0] = toupper(result[i][0]);
        cout << result[i] << "\n";
    }
    return 0;
}