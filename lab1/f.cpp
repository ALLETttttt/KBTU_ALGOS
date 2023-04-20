#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n, cnt = 0;
    cin >> n;
    stack <int> st;
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
            st.push(i);
        }
        if (cnt == n){
            cout << st.top();
            break;
        }
        
    }
    return 0;
}