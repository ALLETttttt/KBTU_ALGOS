#include <iostream>
using namespace std;

int main(){
    int n; cin >> n; char a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    char aa; cin >> aa;
    int ll = 0, rr = n - 1;

    while(ll <= rr){
        int mid = ll + (rr-ll)/2;
        if(a[mid] == a[n-1]){
            cout << a[0];
            break;
        }
        else if(aa == a[mid]){
            cout << a[mid+1];
            break;
        }
        else if(aa < a[mid] && a[ll] < a[mid]){
            cout << a[ll];
            break;
        }
        else if(aa < a[mid]){
            rr = mid - 1;
        }
        else if(aa > a[mid]){
            ll = mid + 1;
        }
    }
}