#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct MaxHeap{
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
        this->v.push_back(value);
        ll i = this->v.size() - 1;
        while(i != 0 && this->v[parent(i)] < this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
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

    int extractMax(){
        if(this->v.size() == 0) return INT_MIN;
        if(this->v.size() == 1){
            ll root = this->v[0];
            this->v.pop_back();
            return root;
        }
        ll root = this->v[0];
        this->v[0] = this->v[this->v.size() - 1];
        this->v.pop_back();
        heapify(0);
        return root;
    }
};

int main(){
    MaxHeap mh;
    ll n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        ll x; cin >> x; mh.insert(x);
    }
    ll sum = 0;
    for(int i = 0; i < k; i++){
        ll root = mh.extractMax();
        sum += root;
        mh.insert(root-1);
    }
    cout << sum;
}