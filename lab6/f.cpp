#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool comparator(pair<pair<string, string>, double > &p1, pair<pair<string, string>, double > &p2){
    if (p1.second == p2.second) {
        if (p1.first.first == p2.first.first) {
            return p1.first.second < p2.first.second;
        }
        return p1.first.first < p2.first.first;
    }
    return p1.second < p2.second;
}

int partition(vector <pair<pair<string, string>, double > > &v, int ll, int rr){
    pair<pair<string, string>, double > pivot = v[rr];
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

void quicksort(vector <pair<pair<string, string>, double > > &v, int ll, int rr){
    if(ll < rr){
        int p = partition(v, ll, rr);
        quicksort(v, ll, p - 1);
        quicksort(v, p + 1, rr);
    }
}

int main(){
    int n, k, credits; cin >> n;
    vector <pair<pair<string, string>, double > > v;
    for(int i = 0; i < n; i++){
        double gpa = 0; double numOfSub = 0;
        string lastname, firstname, grade; 
        cin >> lastname >> firstname >> k;
        for(int j = 0; j < k; j++){
            cin >> grade >> credits;
            numOfSub += credits;
            if(grade == "A+"){gpa += credits * 4;}
            else if(grade == "A"){gpa += credits * 3.75;}
            else if(grade == "B+"){gpa += credits * 3.5;}
            else if(grade == "B"){gpa += credits * 3;}
            else if(grade == "C+"){gpa += credits * 2.5;}
            else if(grade == "C"){gpa += credits * 2;}
            else if(grade == "D+"){gpa += credits * 1.5;}
            else if(grade == "D"){gpa += credits * 1;}
            else if(grade == "F"){gpa += credits * 0;}  
        }
        v.push_back({{lastname, firstname}, (gpa/numOfSub)});
        // cout << lastname << " " << firstname << " " << gpa/numOfSub << "\n";
    }
    quicksort(v, 0, v.size() -  1);
    for(auto i : v){
        cout << i.first.first << " " << i.first.second << " " << fixed << setprecision(3) << i.second << "\n";
    }
}