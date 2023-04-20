#include <iostream>
using namespace std;

int binary_search_incr(int arr[], int target, int size){
	int r = size-1, l = 0, centre;
	while(l <= r){
		centre = l + (r-l) / 2;
		if(target < arr[centre]){
			r = centre - 1;
		}
		else if(target > arr[centre]){
			l = centre + 1;
		}
		else{
			return centre;
		}
	}
	return -1;
}

int binary_search_decr(int arr[], int point, int size){
	int r = size-1, l = 0, centre;
	while(l <= r){
		centre = l + (r-l) / 2;
		if(point > arr[centre]){
			r = centre - 1;
		}
		else if(point < arr[centre]){
			l = centre + 1;
		}
		else{
			return centre;
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	int a, b;
	cin >> a >> b;
	int matrix[a][b];
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> matrix[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a; j++){
			int index;
			if(j % 2 == 0){
				index = binary_search_decr(matrix[j], ar[i], b);
			}
			else{
				index = binary_search_incr(matrix[j], ar[i], b);
			}
			if(index != -1){
				cout << j << " " << index << endl;
				break;
			}
			else if(index == -1 && j == a-1){
				cout << -1 << endl;
				break;
			}
		}
	}
}