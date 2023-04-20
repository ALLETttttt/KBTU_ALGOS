#include <iostream>
#include <deque>
using namespace std;

int main(){
    int a[5], b[5];
    deque <int> dq1;
    deque <int> dq2;
    for(int i = 0; i < 5; i++){
        cin >> a[i];
        dq1.push_back(a[i]);
    }
    for(int i = 0; i < 5; i++){
        cin >> b[i];
        dq2.push_back(b[i]);
    }
    int cnt = 0;
    while(!dq1.empty() && !dq2.empty()){
        if(cnt > 1000000){
            cout << "blin nichya";
            return 0;
        }
        if(dq1.front() == 9 && dq2.front() == 0){
            dq2.push_back(dq1.front());
            dq2.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() == 0 && dq2.front() == 9){
            dq1.push_back(dq1.front());
            dq1.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() > dq2.front()){
            dq1.push_back(dq1.front());
            dq1.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() < dq2.front()){
            dq2.push_back(dq1.front());
            dq2.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        cnt++;
    }
    if(dq1.empty()){
        cout << "Nursik " << cnt;
    }
    if(dq2.empty()){
        cout << "Boris " << cnt;
    }
    return 0;
}