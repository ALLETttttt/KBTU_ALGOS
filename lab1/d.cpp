#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string s){
    stack <int> st;
    for (int i = 0; i < s.size(); i++){
        if (st.empty()){
            st.push(s[i]);
        }
        else if (st.top() == s[i])
        {
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    if (isBalanced(s)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}