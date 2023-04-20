#include <iostream> 
#include <vector> 
#include <set> 
using namespace std; 

int INF = 1e9, n, m; 
vector<pair<int,int>> g[200005]; 
vector<int> dxvectr(200005, INF); 

int dxtrasol(int s, int end){ 
    dxvectr.clear(); 
    for(int i=0;i<200005;i++){ 
        dxvectr[i] = INF; 
    } 
    dxvectr[s] = 0; 
    set< pair<int,int> > setl; 
    setl.insert(make_pair(dxvectr[s],s)); 
    while(!setl.empty()){ 
        int k = setl.begin()->second; 
        setl.erase(setl.begin()); 
        for(int j = 0;j<g[k].size();j++){ 
            int by = g[k][j].first; 
            int length = g[k][j].second; 
            if(dxvectr[k] + length < dxvectr[by]){ 
                setl.erase(make_pair(dxvectr[by], by)); 
                dxvectr[by] = dxvectr[k] + length; 
                setl.insert(make_pair(dxvectr[by], by)); 
            } 
        } 
    } 
    return dxvectr[end]; 
} 



int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int x,y,z; 
        cin >> x >> y >> z; 
        g[x].push_back({y,z}); 
        g[y].push_back({x,z}); 
    } 
    int f, s, t, fo; 
    cin >> f >> s >> t >> fo; 
    int x, y; 
    x = dxtrasol(f,s) + dxtrasol(s,t) + dxtrasol(t,fo); 
    y = dxtrasol(f,t) + dxtrasol(t,s) + dxtrasol(s,fo) ; 
    if(min(x,y) <= INF){ 
        cout << min(x,y); 
    }else{ 
        cout << -1; 
    } 
    return 0; 
}