#include <iostream>
#include <vector>
using namespace std;

bool comp(pair<string, string> v1, pair<string, string> v2){
    return v1.first < v2.first;
}


int partition(vector <pair<string, string> > &v, int ll, int rr){
    pair<string, string> pivot = v[rr];
    int index = ll;
    for(int i = ll; i < rr; i++){
        if(comp(v[i], pivot)){
            swap(v[i], v[index]);
            index++;
        }
    }
    swap(v[index], v[rr]);
    return index;
}

void quicksort(vector <pair<string, string> > &v, int ll, int rr){
    if(ll < rr){
        int p = partition(v, ll, rr);
        quicksort(v, ll, p - 1);
        quicksort(v, p + 1, rr);
    }
}

int main(){
    int n; cin >> n; vector <pair<string, string> > v;
    for(int i = 0; i < n; i++){
        bool target = false;
        string ff, ss; cin >> ff >> ss;
        for(int i = 0; i < v.size(); i++){
            if(ff == v[i].second){
                v[i].second = ss;
                target = true;
                break;
            }
        }
        if(!target){v.push_back({ff, ss});}
    }
    quicksort(v, 0, v.size() - 1);
    cout << v.size() << "\n";
    for(auto i : v){
        cout << i.first << " " << i.second << "\n";
    }
}