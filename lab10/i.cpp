#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> saw;
vector<int> topsort, colors;

bool findCycle(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (findCycle(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

void topSort(int v) {
	saw[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!saw[u]) {
			topSort(u);
		}
	}
	topsort.push_back(v);
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	saw.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	bool cycle = false;
	for (int i = 0; i < m; i++) {
		if (findCycle(i)) {
			cycle = true;
			break;
		}
	}
	if (!cycle) {
		cout << "Possible\n";
		for (int i = 0; i < m; i++) {
			if (!saw[i]) {
				topSort(i);
			}
		}
		for (int i = topsort.size() - 1; i >= 0; i--) {
			cout << topsort[i] + 1 << " ";
		}
	} else {
		cout << "Impossible";
	}

	return 0;
}