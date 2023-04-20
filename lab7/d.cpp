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

void merge(vector <pair<pair<string, string>, double > > &v, int ll, int rr, int mid){
    auto const first = mid - ll + 1;
    auto const second = rr - mid;
    vector <pair<pair<string, string>, double > > left(first);
    vector <pair<pair<string, string>, double > > right(second);
   

    for(auto i = 0; i < first; i++){
        left[i] = v[ll + i];
    }

    for(auto j = 0; j < second; j++){
        right[j] = v[j + mid + 1];
    }

    int l = 0, r = 0, lr = ll;

    while(l < left.size() && r < right.size()){
        if(comparator(left[l], right[r])){
            v[lr] = left[l];
            l++;
        }
        else{
            v[lr] = right[r];
            r++;
        }
        lr++;
    }

    while(l < left.size()){
        v[lr] = left[l];
        l++;
        lr++;
    }

    while(r < right.size()){
        v[lr] = right[r];
        r++;
        lr++;
    }
}

void mergesort(vector <pair<pair<string, string>, double > > &v, int ll, int rr){
    if(ll >= rr){
        return;
    }
    int mid = ll + (rr-ll)/2;
    mergesort(v, ll, mid);
    mergesort(v, mid + 1, rr);
    merge(v, ll, rr, mid);
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
    mergesort(v, 0, v.size() - 1);
    for(auto i : v){
        cout << i.first.first << " " << i.first.second << " " << fixed << setprecision(3) << i.second << "\n";
    }
}