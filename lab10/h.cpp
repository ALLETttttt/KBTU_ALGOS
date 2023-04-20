#include <bits/stdc++.h>
using namespace std;
int cnt, n, m;

void dfs(char **arr, int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == '0') return;
	arr[i][j] = '0';
	dfs(arr, i + 1, j);
	dfs(arr, i - 1, j);
	dfs(arr, i, j + 1);
	dfs(arr, i, j - 1);
}


int main(){
	cin >> n >> m;
	char **arr = new char* [n];
	for(int i = 0; i < n; i++){
		arr[i] = new char [m];
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == '1'){
				dfs(arr, i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}