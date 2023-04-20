#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    queue <int> q;
    stack <int> st;
    int n, cnt = 0;
    cin >> n;
    int a[100000];
    st.push(n);
    for (int i = 2; i <= 10000; i++){
        bool target = true;
        for (int j = 2; j <= i-1; j++){
            if (i % j == 0)
            {
                target = false;
                break;
            }
        }
        if(target == true){
            cnt++;
            if (isPrime(cnt) && isPrime(i)){
                q.push(i);
            }
        }
    }
    vector <int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    cout << v[st.top()-1];
    return 0;
}