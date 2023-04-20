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

int main(){
    int n, z; cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str >> z;
        auto result = getPref(str);
        int res = str.size() - result.back();
        cout << res * (z - 1) + str.size() << "\n";
    }
}