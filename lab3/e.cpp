#include <iostream>
using namespace std;
// int binary_search(int a[], int n, int k){
//     int startIndex = -1;
//     int l = 0, r = n - 1, m, cnt = 0, i = 0;
//     while(l <= r){
//         int m = l + (r-l)/2;
//         if(m > a[i]){
//             cnt++;
//         }
//         if(cnt >= k){
//             r = m - 1;
//         }
//         else if (cnt < k){
//             l = m + 1;
//         }
//         i++;
//     }
//     return r;
// }

// int main(){
//     int n, k;
//     cin >> n >> k;
//     int a[n];

//     for(int i = 0; i < n; i++){
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;  
//         a[i] = max(x2, y2);
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(a[j] > a[j+1]){
//                 swap(a[j], a[j+1]);
//             }
//         }
//     }
//     for(int i = 0; i < n; i++){
//         cout << a[i] << " ";
//     }
//     cout << binary_search(a, n, k);
// }

#include <iostream>
#include <algorithm>
using namespace std;

bool check_is_inside(int x, int y, int square){
    return square >= x and square >= y;
}

int check(int a[], int b[], int size, int x){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(check_is_inside(a[i], b[i], x)){
            count++;
        }
    }
    return count;
}


int main(){
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    long long left = 0, right = 0;
    for(int i = 0; i < n; i++){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = x2;
        b[i] = y2;
        right = max(max(x2, y2), right);
    }
    int startindex = -1;
    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(check(a, b, n, mid) == k){
            startindex = mid;
            right = mid - 1;
        }
        else if(check(a, b, n, mid) > k){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(startindex == -1){
        startindex = left;
    }
    cout << startindex;
}