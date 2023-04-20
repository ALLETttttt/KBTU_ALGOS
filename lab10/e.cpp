#include <iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int array[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> array[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        if(array[a][b] && array[b][c] && array[a][c]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}