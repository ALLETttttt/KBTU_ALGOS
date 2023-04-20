#include <iostream>
using namespace std;

// void search(int a[], int size, int x){
//     int cnt = 0, sum = 0;
//     for(int i = 0; i < size; i++){
//         if(a[i]  <= x){
//             cnt++;
//             sum += a[i];
//         }
//     }
//     cout << cnt << " " << sum << endl;
// }

// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int p;
//     cin >> p;
//     int g[p];
//     for(int i = 0; i < p; i++){
//         cin >> g[i];
//         search(a, n, g[i]);
//     }
// }

#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a[i] = t;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
    int p; cin >> p;
    for(int i = 0; i < p; i++){
        int t; cin >> t;
        int l = 0, r = n - 1, m;
        int cnt = 0, cnt2 = 0;
        while(r >= l){
            m = l + (r - l) / 2;
            if(a[r] <= t){
                cnt = r + 1;
                break;
            }
            if(a[m] > t) r = m - 1;
            else if(a[m] <= t){
                l = m + 1;
                cnt = m + 1;
            }
        }
        for(int i = 0; i < cnt; i++){
            cnt2 += a[i];
        }
        
        cout << cnt << " " << cnt2 << endl;
    }

    return 0;
}