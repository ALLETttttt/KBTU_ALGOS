#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n;
    char a;
    deque <int> dq;
    while(cin >> a){
        if(a == '!'){
            break;
        }
        if(a == '+'){
            cin >> n;
            dq.push_front(n);
        }
        if(a == '-'){
            cin >> n;
            dq.push_back(n);
        }
        if(a == '*'){
            if(dq.size() >= 2){
                cout << dq.front() + dq.back() << endl;;
                dq.pop_back();
                dq.pop_front();
            }
            else if(dq.size() == 1){
                cout << dq.front()*2 << endl;;
                dq.pop_front();
            }
            else if(dq.size() == 0){
                cout << "error" << endl;;
            }
        }
    }
}