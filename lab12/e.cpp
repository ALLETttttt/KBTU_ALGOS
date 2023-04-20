#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1e9;
bool crug = false;
void solve() {
    vector<int> dxtravec(n, INF);
    dxtravec[v] = 0;
    vector<int> asp (n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < n * n; ++j)
            if (dxtravec[e[j].a] < INF)
                if (dxtravec[e[j].b] > dxtravec[e[j].a] + e[j].cost) {
                    dxtravec[e[j].b] = max (-INF, dxtravec[e[j].a] + e[j].cost);
                    asp[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        crug = false;
    else {
        int y = x;
        for (int i=0; i<n; ++i)
            y = asp[y];

        vector<int> vecpath;
        for (int now=y; ; now=asp[now]) {
            vecpath.push_back (now);
            if (now == y && vecpath.size() > 1)  break;
        }
        reverse (vecpath.begin(), vecpath.end());

        cout << "YES" << endl;
        cout << vecpath.size() << endl;
        for (size_t i=0; i<vecpath.size(); ++i)
            cout << vecpath[i] + 1 << ' ';
        cout << endl;
        crug = true;
    }
}

int main(){
    cin >> n;
    vector<int> dxtravec(n, INF);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            edge now;
            cin >> now.cost;
            now.a = i; now.b = j;
            e.push_back(now);
        }
    }

    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if (crug) break;
    }
    if (!crug) cout << "NO" << endl;
}