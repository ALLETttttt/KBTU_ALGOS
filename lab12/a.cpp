#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long N = 500+5 , inf = 2e9 + 7;


int arr[N][N];
int g[N][N];
int p[N];
int n; 

void result(int tc) {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> arr[i][j];
            g[i][j] = inf;
        }
    }
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
        int res = 0;
        for(int j = 1; j <= i; j ++) {
            int a = p[j], b = p[i];
            g[a][b] = arr[a][b];
            g[b][a] = arr[b][a];
        }
        for(int k = 1; k <= i; k ++) {
            for(int t = 1; t <= i; t ++) {
                int a = p[t], b = p[i], c = p[k];
                g[a][b] = min(g[a][b] , g[a][c] + g[c][b]);
            }
        }
        for(int k = 1; k <= i; k ++) {
            for(int t = 1; t <= i; t ++) {
                int a = p[i], b = p[t], c = p[k];
                g[a][b] = min(g[a][b] , g[a][c] + g[c][b]);
            }
        }
        for(int k = 1; k <= i; k ++) {
            for(int t = 1; t <= i; t ++) {
                int a = p[k], b = p[t], c = p[i];
                g[a][b] = min(g[a][b] , g[a][c] + g[c][b]);
                if(g[a][b] < inf) {
                    res = max(res, g[a][b]);
                }
            }
        }
        cout << res << '\n';
    }
}
int main() {

    int f = 1 , cnt = 0;
    while(f --) {
        result(++cnt);
    }
    return 0;
}