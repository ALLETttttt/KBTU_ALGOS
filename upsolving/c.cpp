#include <bits/stdc++.h>
using namespace std;

struct heap{
    vector <int> v;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i + 1;
    }

    int right(int i){
        return 2*i + 2;
    }

    void insert(int val){
        this->v.push_back(val);
        int i = this->v.size() - 1;
        while(i != 0 && this->v[parent(i)] < this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = this->left(i);
        int r = this->right(i);
        int smallest = i;
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

    void add(int index, int val){
        this->v[index-1] += val;
        int i = index - 1;
        while(i != 0 && this->v[parent(i)] < this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
        }
        cout << i + 1 << endl;
    }

    void getCurHeap(){
        for(int i = 0; i < this->v.size(); i++){
            cout << this->v[i] << " ";
        }
    }
};

int main(){
    heap hp;
    int n, q; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x; hp.insert(x);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int index, val;
        cin >> index >> val;
        hp.add(index, val);
    }
    hp.getCurHeap();
}