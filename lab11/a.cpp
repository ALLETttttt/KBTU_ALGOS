#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	long long sum = 0;
	cin >> n >> m;
	vector<pair<int,pair<int,int> > > v;
	for (int i = 0; i < m; i++){
		int l, r, c;
		cin >> l >> r >> c;
		v.push_back({c, {l, r}});
	}

	sort(v.begin(),v.end());
	int limit = 2;
	while(limit <= n){
		for(int i=0;i<v.size();i++){
			int x = v[i].second.first,  y = v[i].second.second,  cost = v[i].first;
			if(x < limit && limit <= y){
				sum += cost;
				limit++;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}