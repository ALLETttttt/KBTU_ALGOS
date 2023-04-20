#include <iostream>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if(i == 0) a[i] = t;
        else a[i] = a[i - 1] + t;
    }
    int t;
    for(int i = 0; i < k; i++){
        int l = 0, r = n - 1, m, cnt = 0;
        cin >> t;
        while(l <= r){
            m = l + (r - l) / 2;
            if(a[m] == t){
                cnt = m;
                break;
            } else if(a[m] > t){
                cnt = m;
                r = m - 1;
            } else l = m + 1;
        }
        cnt += 1;
        cout << cnt << endl;
    }
    return 0;
}
