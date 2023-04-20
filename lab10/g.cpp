#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > g;
vector<int> colors;

bool findCycle(int v, pair<int, int> side) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (v == side.first && u == side.second) continue;
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (findCycle(u, side)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

int main() {
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			bool cycle = false;
			for (int k = 0; k < m; k++) {
				if (findCycle(k, { i, g[i][j] })) {
					cycle = true;
					break;
				}
			}
			if (!cycle) {
				cout << "YES";
				return 0;
			}
			colors.assign(m, 0);
		}
	}
	cout << "NO";
	return 0;
}