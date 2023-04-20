#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    queue <int> qqq;
    for(int i = 0; i < n; i++){
        int mt; cin >> mt;
        if(qqq.size() == 0){
            qqq.push(mt);
            cout << 1 << " ";
        }
        else{
            if(mt <= 3000){
                qqq.push(mt);
            }
            else{
                int ping = mt - 3000;
                while(qqq.size() != 0 && qqq.front() < ping){
                    qqq.pop();
                }
                qqq.push(mt);
            }
            cout << qqq.size() << " ";
        }
    }
}