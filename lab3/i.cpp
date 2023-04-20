#include <iostream>
using namespace std;
bool binary_search(int a[], int n, int k){
    int l = 0, r = n-1;
    bool ok = false;
    while(l <= r){
        int centre = l + (r-l)/2;
        if(a[centre] == k){
            return true;
        }
        else if(a[centre] > k){
            r = centre - 1;
        }
        else if(a[centre] < k){
            l = centre + 1;
        }
    }
    return false;
} 
int main(){
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    if(binary_search(a, n, k)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}