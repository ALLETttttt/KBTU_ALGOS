#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long mod = 9007199254740881;
	string s; cin >> s;

	vector<vector<long long>>viv;
	unordered_map<long long,int> unmp;

	for(int i = 0; i < s.size(); i++){
	long long res = 0;
	long long N = 256;

	    for(int j = i; j < s.size(); j++){

		    res = (res*N+s[j]) % mod;
		    if(unmp.find(res) == unmp.end()) viv.push_back({i, j});
			
		    unmp[res] = 1;
	    }
    }
	cout<<viv.size()<<endl;
}


