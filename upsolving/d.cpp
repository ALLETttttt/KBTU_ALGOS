#include <iostream>
#include <vector>
using namespace std;

bool findMePrimePLS(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}


int main(){
	int n; cin >> n;
	vector <int> v;
	for(int i = 2; i <= n; i++){
		if(n % i == 0 && findMePrimePLS(i)){
			v.push_back(i);
			while(n % i == 0){
				n /= i;
			}
		}
	}
	cout << v.size();
}