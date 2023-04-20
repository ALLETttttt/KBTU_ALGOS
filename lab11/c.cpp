#include <bits/stdc++.h>
using namespace std;

vector <int> predok;

int get(int n){
    if(n == predok[n]){
        return n;
    }
    else return predok[n] = get(predok[n]);
}

void unite(int f, int s){
    s = get(s); f = get(f);
    if(f != s){
        predok[f] = s;
    }
}

int main(){
    vector <pair <int, pair <int, int > > > v;  
    int n, m, x, y, sum = 0; cin >> n >> m >> x >> y;
    predok.resize(n);
    for(int i = 0; i < m; i++){
        string s; int a, b, c;
        cin >> s >> a >> b >> c;
        a--; b--;
        if(s == "big") c *= x;
        else if(s == "small") c *= y;
        else if(s == "both") c *= min(x, y);
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++ i){
        predok[i] = i;
    }
    for(int i = 0; i < v.size(); ++i){
        int f = v[i].second.first;
        int s = v[i].second.second;
        int amount = v[i].first;
        if(get(f) != get(s)){
            sum += amount;
            unite(f, s);
        }
    }
    cout << sum;
}