#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> ll, vector<int> rr) {
	vector<int> fin;
	int l = 0, r = 0;
	while (l < ll.size() && r < rr.size()) {
		if (ll[l] <= rr[r]) {
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

vector<int> mergesort(vector<int> v, int l, int r) {
	if (l == r) {
		vector<int> fin;
		fin.push_back(v[l]);
		return fin;
	}
	int m = l + (r - l) / 2;
	vector<int> left = mergesort(v, l, m);
	vector<int> right = mergesort(v, m + 1, r);
	return merge(left, right);
}


int main(){
    int n, m, l = 0, r = 0; cin >> n >> m;
    vector <int> xx, yy;
    for(int i = 0; i < n; i++){
        int x; cin >> x; xx.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int y; cin >> y; yy.push_back(y);
    }
    if(n == 0 || m == 0){
        return 0;
    }

    auto xxx = mergesort(xx, 0, xx.size() - 1);
    auto yyy = mergesort(yy, 0, yy.size() - 1);
    
    while(l < xxx.size() && r < yyy.size()){
        if(xxx[l] == yyy[r]){
            cout << xxx[l] << " ";
            l++;
            r++;
        }
        else if(xxx[l] > yyy[r]){
            r++;
        }
        else if(xxx[l] < yyy[r]){
            l++;
        }
    }
}