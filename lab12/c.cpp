#include <bits/stdc++.h>

using namespace std; 

vector<int>g1[410]; 
vector<int>g2[410]; 
int arrayy[405][405]; 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    for(int i=0;i<m;i++){ 
        int x,y; 
        cin >> x >> y; 
        x--; 
        y--; 
        g1[x].push_back(y); 
        g1[y].push_back(x); 
        arrayy[x][y] = 1; 
        arrayy[y][x] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arrayy[i][j] == 0 && i != j){ 
                g2[i].push_back(j); 
            } 
        } 
    } 
    queue<int>qq; 
    vector<int>dxtr(n+1); 
    vector<bool>saw(n+1); 
    qq.push(0); 
    saw[0] = true; 
    while(!qq.empty()){ 
        int k = qq.front(); 
        qq.pop(); 
        for(int i=0;i<g1[k].size();i++){ 
            int to = g1[k][i]; 
            if(!saw[to]){ 
                saw[to] = true; 
                qq.push(to); 
                dxtr[to] = dxtr[k]+1; 
            } 
        } 
    } 
    queue<int>q; 
    vector<int>d2(n+1); 
    vector<bool>saw2(n+1); 
    q.push(0); 
    saw2[0] = true; 
    while(!q.empty()){ 
        int k = q.front(); 
        q.pop(); 
        for(int i=0;i<g2[k].size();i++){ 
            int to = g2[k][i]; 
            if(!saw2[to]){ 
                saw2[to] = true; 
                q.push(to); 
                d2[to] = d2[k]+1; 
            } 
        } 
    } 
    if (!saw[n-1] || !saw2[n-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(dxtr[n-1], d2[n-1]); 
    } 
}