#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, i = 2;
    cin >> n;
    int k = n - i;
    while(k != i-1){
        if(isPrime(i) && isPrime(k)){
            cout << i << " " << k;
            break;
        }
        k--;
        i++;
    }
}