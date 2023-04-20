#include <bits/stdc++.h>
using namespace std;

struct heap{
    vector <int> v;

    int parent(int i){
        return (i-1)/2;
    }

    int right(int i){
        return 2*i + 2;
    }

    int left(int i){
        return 2*i + 1;
    }

    void insert(int val){
        this->v.push_back(val);
        int i = this->v.size() - 1;
        while(i != 0 && this->v[parent(i)] < this->v[i]){
            swap(this->v[parent(i)], this->v[i]);
            i = parent(i);
        }
    }

    int countOf(){
        int counter = 0;
        for(int i = 0; this->right(i) < this->v.size(); i++){
            if(this->v[this->right(i)] > this->v[this->left(i)]){
                counter++;
            }
        }
        return counter;
    }
};

int main(){
    int n; cin >> n; heap hp;
    for(int i = 0; i < n; i++){
        int x; cin >> x; hp.insert(x);
    }
    cout << hp.countOf();
}