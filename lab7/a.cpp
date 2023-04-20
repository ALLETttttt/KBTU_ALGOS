#include <iostream>
#include <vector>
using namespace std;

bool comparator(string s1, string s2){
    return s1.size() <= s2.size();
}

vector <string> getString(string s){
    vector <string> qwe;
    s += " ";
    string emp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            emp += s[i];
        }
        else if(s[i] == ' ' || i == s.size() - 1){
            qwe.push_back(emp);
            emp = "";
        }
    }
    return qwe;
}

vector <string> merge(vector <string> ll, vector <string> rr){
    vector <string> fin;
    int l = 0, r = 0;
    while(l < ll.size() && r < rr.size()){
        if(comparator(ll[l], rr[r])){
            fin.push_back(ll[l]);
            l++;
        }
        else{
            fin.push_back(rr[r]);
            r++;
        }
    }
    while(l < ll.size()){
        fin.push_back(ll[l]);
        l++;
    }
    while(r < rr.size()){
        fin.push_back(rr[r]);
        r++;
    }
    return fin;
}

vector <string> mergesort(vector <string> v, int l, int r){
    if(l == r){
        vector <string> vv;
        vv.push_back(v[l]);
        return vv;
    }
    int m = l + (r-l)/2;
    vector <string> left = mergesort(v, l, m);
    vector <string> right = mergesort(v, m + 1, r);
    return merge(left, right);
}

int main(){
    int n; cin >> n; vector <string> v;
    for(int i = 0; i < n + 1; i++){
        string s; 
        getline(cin, s);
        if(i == 0){continue;}
        auto v = getString(s);
        auto res = mergesort(v, 0, v.size() - 1);
        for(auto ss : res){
            cout << ss << " ";
        }
        cout << "\n";
    }
}