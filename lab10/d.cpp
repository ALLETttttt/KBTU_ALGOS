#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector <int> g[7777];
int inf[7777];


void bfs(int y){
    queue <int> q;
    q.push(y);
    inf[y] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int i = 0; i < g[k].size(); i++){
            int so = g[k][i];
            if(inf[so] > inf[k] + 1){
                inf[so] = inf[k] + 1;
                q.push(so);
            }
        }
    }
}


int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        inf[i] = 1e9;
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        if(x == 1){
            bfs(y);
        }
        else{
            if(inf[y] == 1e9) cout << -1 << "\n";
            else cout << inf[y] << "\n"; 
        }
    }
}