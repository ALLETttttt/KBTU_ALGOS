#include <iostream>
using namespace std;

int partition(int arar[], int ll, int rr){
    int pivot = arar[rr];
    int index = ll;
    for(int i = ll; i < rr; i++){
        if(arar[i] > pivot){
            swap(arar[i], arar[index]);
            index++;
        }
    }
    swap(arar[index], arar[rr]);
    return index;
}

void quicksort(int arar[], int ll, int rr){
    if(ll < rr){
        int p = partition(arar, ll, rr);
        quicksort(arar, ll, p - 1);
        quicksort(arar, p + 1, rr);
    }
}

int main(){
    int n, m; cin >> n >> m;
    int arar[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arar[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        quicksort(arar[i], 0, n - 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arar[j][i] << " ";
        }
        cout << "\n";
    }
}