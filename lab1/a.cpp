#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m;
        deque <int> dq;
        for (int j = m; j > 0; j--){
            dq.push_back(j);
            for (int k = 0; k <= j; k++){
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
}