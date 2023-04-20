#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0; cin >> n;
    int a[n][n]; queue <int> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int aa, b; 
    cin >> aa >> b;
    aa--; b--;
    if(aa == b){
        cout << cnt;
        return 0; 
    }

    q.push(aa);
    vector <bool> saw(n);
    saw[aa] = true;
    while(!q.empty()){
        int qq = q.front();
        cnt++;
        for(int i = 0; i < n; i++){
            if(!saw[i] && a[qq][i]){
                if(i == b){
                    cout << cnt;
                    return 0;
                }
                saw[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << -1;
}