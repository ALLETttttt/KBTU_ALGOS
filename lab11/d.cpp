#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n, res = 0; cin >> n;
    vector <int> mx(n, INF), mn(n, -1);
    vector <vector <int> > g(n);
    vector <bool> saw(n);
    for(int i = 0; i < n; i++){
        g[i].resize(n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    mx[0] = 0;
    for(int i = 0; i < n; i++){
        int a = -1;
        for(int j = 0; j < n; j++){
            if(!saw[j] && (a == -1 || mx[j] < mx[a])){
                a = j;
            }
        }
        saw[a] = true;
        if(mn[a] != -1){
            res += g[a][mn[a]];
        }

        for(int j = 0; j < n; j++){
            if(g[a][j] < mx[j]){
                mx[j] = g[a][j];
                mn[j] = a;
            }
        }
    }
    cout << res;
}