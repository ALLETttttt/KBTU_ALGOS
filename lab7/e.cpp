#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>& v1, vector<int>& v2) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < v1.size(); i++) {
		sum1 += v1[i];
		sum2 += v2[i];
	}
	if (sum1 == sum2) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] < v2[i]) {
				return true;
			}
			else if(v1[i] > v2[i]){
				return false;
			}
		}
	}

	return sum1 > sum2;
}

vector<vector<int> > merge(vector<vector<int> > &ll, vector<vector<int> > &rr) {
	vector<vector<int> > fin;
	int l = 0, r = 0;
	while (l < ll.size() && r < rr.size()) {
		if (comparator(ll[l], rr[r])) {
			fin.push_back(ll[l]);
			l++;
		} else {
			fin.push_back(rr[r]);
			r++;
		}
	}
	while (l < ll.size()) {
		fin.push_back(ll[l]);
		l++;
	}
	while (r < rr.size()) {
		fin.push_back(rr[r]);
		r++;
	}
	return fin;
}

vector<vector<int> > mergesort(vector<vector<int> > a, int l, int r) {
	if (l == r) {
		vector<vector<int> > fin;
		fin.push_back(a[l]);
		return fin;
	}
	int m = l + (r - l) / 2;
	vector<vector<int> > left = mergesort(a, l, m);
	vector<vector<int> > right = mergesort(a, m + 1, r);
	return merge(left, right);
}


int main() {
	int n, m; cin >> n >> m;
	vector <vector<int> > v;
	for (int i = 0; i < n; i++) {
		vector<int> vv;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			vv.push_back(x);
		}
		v.push_back(vv);
	}
	auto topVect = mergesort(v, 0, v.size() - 1);
	for (auto i : topVect) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}