#include <bits/stdc++.h>
using namespace std;

struct heap{
    vector <int> v;
    int left(int i){
        return 2*i + 1;
    }

    int right(int i){
        return 2*i + 2;
    }

    int parent(int i){
        return (i-1)/2;
    }

    int insert(int val){
        v.push_back(val);
        int i = this->v.size() - 1;
        while(i != 0 && this->v[parent(i)] > this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = this->left(i);
        int r = this->right(i);
        int smallest = i;
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
            int root = this->v[0];
            this->v.pop_back();
            return root;
        }
        int root = this->v[0];
        this->v[0] = this->v.back();
        this->v.pop_back();
        heapify(0);
        return root;
    }

    int getSize(){
        return this->v.size();
    }
};

int main(){
    heap hp, ph;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        hp.insert(x);
    }
    for(int i = 0; i < k; i++){
        int xx; cin >> xx;
        ph.insert(xx);
    }
    while(hp.getSize() != 0 && ph.getSize() != 0){
        int g = hp.extract();
        int gg = ph.extract();
        if(g == gg){
            cout << g << " ";
        }
        else if(g < gg){
            ph.insert(gg);
        }
        else if(g > gg){
            hp.insert(g);
        }
    }
}