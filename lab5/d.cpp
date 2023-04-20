#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Heap{
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
        ll i = this->v.size() - 1;
        while(i != 0 && this->v[parent(i)] > this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
        }
    }

    void heapify(ll i){
        ll l = left(i);
        ll r = right(i);
        ll smallest = i;
        if(l < this->v.size() && this->v[l] < this->v[smallest]){
            smallest = l;
        }
        if(r < this->v.size() && this->v[r] < this->v[smallest]){
            smallest = r;
        }
        if(smallest != i){
            swap(this->v[i], this->v[smallest]);
            this->heapify(smallest);
        }
    }

    int extract(){
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

    int getSize(){
        return this->v.size();
    }
};

int main(){
    Heap mh;
    ll n, k, nice, cnt = 0; cin >> n >> k;
    for(int i = 0; i < n; i++){
        ll x; cin >> x; mh.insert(x);
    }
    while(mh.getSize() >= 2){
        ll d1 = mh.extract();
        if(d1 >= k){
            nice = d1;
            break;
        }
        ll d2 = mh.extract();
        nice = d1 + d2*2;
        mh.insert(nice);
        cnt++;
    }
    if(nice >= k) cout << cnt;
    else cout << -1;
}
