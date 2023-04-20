#include <iostream>
#include <vector>
using namespace std;

bool comparator(string &s, string &t){
    int years = stoi(s.substr(6, 4));
    int yeart = stoi(t.substr(6, 4));

    int months = stoi(s.substr(3, 2));
    int montht = stoi(t.substr(3, 2));

    int days = stoi(s.substr(0, 2));
    int dayt = stoi(t.substr(0, 2));

    if(years < yeart){return true;}
    if(years == yeart && months < montht){return true;}
    if(years == yeart && months == montht && days < dayt){return true;}
    return false;
}


int partition(vector <string> &v, int ll, int rr){
    string pivot = v[rr];
    int index = ll;
    for(int i = ll; i < rr; i++){
        if(comparator(v[i], pivot)){
            swap(v[i], v[index]);
            index++;
        }
    }
    swap(v[index], v[rr]);
    return index;
}


void quicksort(vector <string> &v, int ll, int rr){
    if(ll < rr){
        int p = partition(v, ll, rr);
        quicksort(v, ll, p - 1);
        quicksort(v, p + 1, rr);
    }
}


int main(){
    int n; cin >> n; vector <string> v;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    quicksort(v, 0, v.size() - 1);
    for(auto i : v){
        cout << i << "\n";
    }
}