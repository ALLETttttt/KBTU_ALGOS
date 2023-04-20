#include <bits/stdc++.h> 
 
using namespace std; 
 
long long getTimeToWork(vector<long long> &bags, long long sz) { 
    long long res = 0; 
    for(auto i : bags) { 
        res += i/sz; 
        if(i%sz) 
            res++; 
    } 
    return res; 
} 
 
int main() { 
 
    long long n, h; 
    cin >> n >> h; 
    vector<long long> bags(n); 
    for(auto &i: bags) 
        cin >> i; 
    long long low = 0, high = 1e18+123; 
    while(low + 1 < high) { 
        long long mid = (low+high)/2; 
        long long timeToWork = getTimeToWork(bags, mid); 
        if(timeToWork <= h) 
            high = mid; 
        else 
            low = mid; 
    } 
    cout << high; 
    return 0; 
}