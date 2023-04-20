#include <iostream>
using namespace std;

int partition(string &ar, int left, int right) {
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

void quick_sort(string &ar, int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quick_sort(ar, left, p - 1);
		quick_sort(ar, p + 1, right);
	}
}

int main() {
	string s; cin >> s;
	quick_sort(s, 0, s.size()-1);
    cout << s;
	return 0;
}