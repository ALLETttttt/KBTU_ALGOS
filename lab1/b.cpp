#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    stack <int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (st.empty())
        {
            cout << -1 << " ";
            st.push(a[i]);
        }
        else
        {
            while(!st.empty() && st.top() > a[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                cout << -1 << " ";
                st.push(a[i]);
            }
            else
            {
                cout << st.top() << " ";
                st.push(a[i]);
            }
        }
    }
    return 0;
}