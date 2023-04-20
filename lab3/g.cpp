#include <iostream>
#include <cmath>
using namespace std;

bool check(int mid, int a[], int size, int k){
    int count = 0;
    for(int i = 0; i < size; i++){
        count = count + ceil(double(a[i]) / mid);
    }
    return(count <= k);
}


int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    long long left = 0, right = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        right += a[i];
    }
    //cout << left << ' ' << right << endl;

    while(right - left >= 0){
        long long mid = (left + right) / 2;
        if(check(mid, a, n, k)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(left == 0){
        left += 1;
    }
    cout << left;
}