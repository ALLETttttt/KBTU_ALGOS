#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Heap{
    vector <ll> v;
    ll capacity;
    ll havchik;

    Heap(ll capacity){
        this->capacity = capacity;
        this->havchik = 0;
    }

    ll parent(ll i){
        return (i-1)/2;
    }

    ll right(ll i){
        return 2*i + 2;
    }

    ll left(ll i){
        return 2*i + 1;
    }

    void insert(ll value){
        v.push_back(value);
        ll size = this->v.size() - 1;
        while(size != 0 && this->v[parent(size)] > this->v[size]){
            swap(this->v[parent(size)], this->v[size]);
            size = parent(size);
        }
    }

    void heapify(ll i){
        ll l = this->left(i);
        ll r = this->right(i);
        ll smallest = i;
        if(l < this->v.size() && this->v[l] < this->v[smallest]){
            smallest = l;
        }
        if(r < this->v.size() && this->v[r] < this->v[smallest]){
            smallest = r;
        }
        if(smallest != i){
            swap(this->v[i], this->v[smallest]);
            heapify(smallest);
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

    void check(int x){
        if(this->v.size() == this->capacity){
            ll minimum = this->extract();
            if(minimum >= x){
                this->insert(minimum);
                return;
            }
            else{
                this->insert(x);
                this->havchik -= minimum;
                this->havchik += x;
            }
        }
        else{
            this->insert(x);
            this->havchik += x;
        }
    }
};

int main(){
    ll n, k; cin >> n >> k;
    Heap heap(k);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "insert"){
            int x; cin >> x; heap.check(x);
        }
        else if(s == "print"){
            cout << heap.havchik << endl;
        }
    }
}