#include <iostream>
using namespace std;

int partition(char ar[], int left, int right) {
	int pivot = ar[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (ar[i] < pivot) {
			swap(ar[i], ar[index]);
			index++;
		}
	}
	swap(ar[index], ar[right]);
	return index;
}

void quick_sort(char ar[], int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quick_sort(ar, left, p - 1);
		quick_sort(ar, p + 1, right);
	}
}

int main() {
	int n; cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k = sizeof(a) / sizeof(a[0]);
    quick_sort(a, 0, k - 1);
    for(int i = 0; i < k; i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            cout << a[i];
        }
    }
    for(int i = 0; i < k; i++){
        if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u'){
            cout << a[i];
        }
    }
}