#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix;


vector<int> getPref(string str) {
    prefix.resize(str.size());
	for (int i = 1; i < str.length(); i++) {
		int j = prefix[i - 1];
		while (j > 0 && str[i] != str[j]) j = prefix[j - 1];
		if (str[i] == str[j]) j++;
		prefix[i] = j;
	}
	return prefix;
}

int main() {
	string str;
	cin >> str;
	vector<int> prefixV = getPref(str);
	cout << str.size() - prefixV.back();
}