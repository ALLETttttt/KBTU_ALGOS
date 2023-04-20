#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack <int> st;
    int n;
    cin >> n;
    if (n <= 1){
        cout << "NO";
    }
    else{
        st.push(n);
        bool target = true;
        for (int i = 2; i*i <= st.top(); i++)
        {
            if (st.top() % i == 0){
                target = false;
                break;
            }
        } 
        if (target == true){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
}