#include <iostream>
#include <deque>
using namespace std;

void revItPLS(deque <int> dq, int l, int r){
    if(l >= r) return;

    swap(dq[l], dq[r]);
    revItPLS(dq, l + 1, r - 1);
}


int main(){
    int n; cin >> n; deque <int> dq;
    bool target = true;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x;
        if(x == 1){
            cin >> y;
            if(target) dq.push_back(y);
            else dq.push_front(y);
        }
        else if(x == 2){
            if(target) target = false;
            else target = true;
        }
    }
    if(target){
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
}