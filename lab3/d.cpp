#include <iostream>
#include <algorithm>
using namespace std;

int find_left(int a[], long long size, int x){
    int startIndex = -1;
    long long l = 0, r = size - 1;
    while(l <= r){
        int centre = l + (r-l)/2;
        if(a[centre] == x){
            startIndex = centre;
            r = centre - 1;
        }
        else if(a[centre] > x){
            r = centre - 1;
        }
        else{
            l = centre + 1;
        }
    }
    if(startIndex == -1){
        return l;
    }
    return startIndex;
}

int find_right(int a[], long long size, int x){
    int endIndex = -1;
    long long l = 0, r = size - 1;
    while(l <= r){
        int centre = l + (r-l)/2;
        if(a[centre] == x){
            endIndex = centre;
            l = centre + 1;
        }
        else if(a[centre] > x){
            r = centre - 1;
        }
        else{
            l = centre + 1;
        }
    }
    if(endIndex == -1){
        return r;
    }
    return endIndex;
}

int count(int a[], long long size, long long l, long long r){
    return find_right(a, size, r) - find_left(a, size, l) + 1;
}

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n - i -1; j++){
    //         if(a[j] > a[j+1]){
    //             swap(a[j], a[j+1]);
    //         }
    //     }
    // }
    sort(a, a + n);
    for(int i = 0; i < q; i++){
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <= l2){
            if(r1 < l2){
                cout << count(a, n, l2, r1) - count(a, n, r2+1, l1-1) << endl; 
            }
            else{
                cout << count(a, n, l1, max(r1, r2)) << endl;
            }
        }
        else{
            if(r2 < l1){
                cout << count(a, n, l2, r1) - count(a, n, r2+1, l1-1)<< endl;
            }
            else{
                cout << count(a, n, l2, max(r1, r2)) << endl;
            }
        }
    }
}