#include <iostream>
#include <vector>
using namespace std;

vector <int> merge(vector <int> ll, vector <int> rr){
	vector <int> fin;
	int l = 0, r = 0;
	while(l < ll.size() && r < rr.size()){
		if(ll[l] <= rr[r]){
			fin.push_back(ll[l]);
			l++;
		}
		else{
			fin.push_back(rr[r]);
			r++;
		}
	}
	while(l < ll.size()){
		fin.push_back(ll[l]);
		l++;
	}
	while(r < rr.size()){
		fin.push_back(rr[r]);
		r++;
	}
	return fin;
}

int main(){
	vector <int> xx, yy;
	int n; cin >> n; 
	for(int i = 0; i < n; i++){
		int x; cin >> x; xx.push_back(x);
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int y; cin >> y; yy.push_back(y);
	}
	auto v = merge(xx, yy);
	for(auto vv : v){
		cout << vv << " ";
	}
}