#include <bits/stdc++.h>
using namespace std;

vector <int> saw(777777, 0);
vector <int> salem(777777, -77);

int main(){
    int x, y; cin >> x >> y;
    queue <int> q;
    q.push(x);
    saw[x] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(k * 2 <= 1e4 && !saw[k*2]){
            salem[k*2] = k;
            q.push(k*2);
            saw[k*2] = saw[k] + 1;
        }
        if(k - 1 > 0 && !saw[k-1]){
            q.push(k-1);
            salem[k-1] = k;
            saw[k-1] = saw[k] + 1;
        }
    }
    cout << saw[y] - 1 << "\n";
    vector <int> result;
    while(salem[y] != -77){
        result.push_back(y);
        y = salem[y];
    }
    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }
}