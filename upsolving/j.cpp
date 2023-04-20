#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ll int x, n; cin >> x >> n; ll int arar[n];
    for(ll int i = 0; i < n; i++){
        cin >> arar[i];
    }
    sort(arar, arar + n);
    ll int l = 0, r = n - 1;
    while(l < r){
        if(arar[l] + arar[r] < x){
            l++;
        }
        else if(arar[l] + arar[r] > x){
            r--;
        }
        else{
            cout << arar[l] << " " << arar[r];
            break;
        }
    }
}