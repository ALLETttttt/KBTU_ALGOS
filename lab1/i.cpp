#include <iostream> 
#include <queue>
#include <stack>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    queue <char> q;
    stack <char> st;
    for(int i = 0; i < n; i++){
        q.push(s[i]);// KSKS
    }
    while(!q.empty()){
        int f = q.front();
        if(st.empty()){
            st.push(f);// st = 0
        }
        else if(st.top() != f){
            q.push(st.top()); // q = KK
            st.pop();
        }
        else{
            st.push(f);
        }
        q.pop();
    }
    if(st.top() == 'K'){
        cout << "KATSURAGI";
    }
    else{
        cout << "SAKAYANAGI";
    }
    return 0;
}