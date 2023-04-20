#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix;

int getPref(string s) {
	int cnt = 0;
	prefix.resize(s.size());
	for (int i = 1; i < s.length() - 1; i++) {
		int j = prefix[i - 1];
		while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
		if (s[i] == s[j]) prefix[i] = j + 1;
		if((i + 1) % (i + 1 - prefix[i]) == 0 && (i + 1)/(i + 1 - prefix[i]) % 2 == 0){ 
            cnt++; 
        } 
	}
	return cnt;
}

int main() {
	string s; cin >> s;
	cout << getPref(s);
}