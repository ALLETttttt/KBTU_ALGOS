#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct MinHeap{
	vector <ll> v;

	ll parent(ll i){
		return (i-1)/2;
	}

	ll left(ll i){
		return 2*i + 1;
	}

	ll right(ll i){
		return 2*i + 2;
	}

	void insert(ll value){
		v.push_back(value);
		ll size = v.size()-1;
		while(size != 0 && this->v[parent(size)] < this->v[size]){
			swap(this->v[parent(size)], this->v[size]);
			size = parent(size);
		}
	}

	void heapify(ll i){
		ll l = this->left(i);
		ll r = this->right(i);
		ll smallest = i;
		if(l < this->v.size() && this->v[l] > this->v[smallest]){
			smallest = l;
		}
		if(r < this->v.size() && this->v[r] > this->v[smallest]){
			smallest = r;
		}
		if(smallest != i){
			swap(this->v[i], this->v[smallest]);
			heapify(smallest);
		}
	}

	int extractMin(){
		if(this->v.size() == 0) return INT_MIN;
		if(this->v.size() == 1){
			ll root = this->v[0];
			this->v.pop_back();
			return root;
		}
		ll root = this->v[0];
		this->v[0] = this->v[this->v.size()-1];
		this->v.pop_back();
		heapify(0);
		return root;
	}

	ll getSize(){
		return this->v.size();
	}
};

int main(){
	MinHeap hp;
	ll n; cin >> n;
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		hp.insert(x);
	}
	while(hp.getSize() != 1){
		ll fy = hp.extractMin();
		ll fx = hp.extractMin();
		if (fx <= fy){
			hp.insert(fy - fx);
		}
	}
	// if(hp.getSize() != 0) 
	cout << hp.extractMin();
	// else cout << 0;
	// for(int i = 0; i < n; i++){
	// 	cout << hp.extractMin();
	// }
}