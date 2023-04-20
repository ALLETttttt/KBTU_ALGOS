#include <bits/stdc++.h>
using namespace std;

struct MinHeap{
    vector <long long> heap;
    long long parent(int i){
        return (i-1)/2;
    }

    long long left(int i){
        return 2*i + 1;
    }

    long long right(int i){
        return 2*i + 2;
    }

    void insert(long long value){
        this->heap.push_back(value);
        long long i = this->heap.size() - 1;
        while(i != 0 && this->heap[parent(i)] > this->heap[i]){
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }

    long long extractMin(){
        if(this->heap.size() == 0) return INT_MIN;
        if(this->heap.size() == 1){
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }

    void heapify(long long i){
        long long l = this->left(i);
        long long r = this->right(i);
        long long smallest = i;
        if(l < this->heap.size() && this->heap[l] < this->heap[smallest]){
            smallest = l;
        }
        if(r < this->heap.size() && this->heap[r] < this->heap[smallest]){
            smallest = r;
        }
        if(smallest != i){
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }

    long long optimize(){
        long long sum = 0;
        while(this->heap.size() != 1){
            long long n1 = this->extractMin();
            long long n2 = this->extractMin();
            sum += n1 + n2;
            this->insert(n1 + n2);
        }
        return sum;
    }
};


int main(){
    MinHeap heap;
    long long n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        heap.insert(x);
    }
    cout << heap.optimize();
}