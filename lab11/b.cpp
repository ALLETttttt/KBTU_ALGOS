#include <iostream>
using namespace std;
int main(){
    int n, res = 1e9, sum = 0; cin >> n; 
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        res = min(res, a[i]);
        sum += a[i];
    }
    cout << (n-1) * res + sum - res;
}