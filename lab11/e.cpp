#include <bits/stdc++.h>
using namespace std;

vector <int> predok;

int get(int v){
    if(v == predok[v]){
        return v;
    }
    else return predok[v] = get(predok[v]);
}

bool unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a != b){
        predok[a] = b;
        return true;
    }
    return false;
}


int main(){
    int n, m, counter = 0;; cin >> n >> m;
    vector <int> v[n];
    predok.resize(n);
    for(int i = 0; i < n; i++){
        predok[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector <int> all;
    for(int i = n-1; i >= 0; i--){
        all.push_back(counter++);
        for(int ii : v[i]){
            if(ii > i) if(unite(i, ii)) counter--;
        }
    }
    for(int i = all.size()-1; i >= 0; i--){
        cout << all[i] << "\n";
    }
}