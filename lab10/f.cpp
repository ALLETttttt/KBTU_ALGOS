#include <iostream>
#include <vector>
using namespace std;
int n, m, s, f, x, y;
bool target;
vector <bool> saw;
vector <vector<int> > v; 

void dfs(int s){
    if(s == f){
        target = true;
        return;
    }
    saw[s] = true;
    for(int i = 0; i < v[s].size(); i++){
        int p = v[s][i];
        if(!saw[p]){
            dfs(p);
        }
    }
}


int main(){
    cin >> n >> m;
    saw.resize(n);
    v.resize(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cin >> s >> f;
    s--; f--;
    dfs(s);
    if(target) cout << "YES";
    else cout << "NO";
}