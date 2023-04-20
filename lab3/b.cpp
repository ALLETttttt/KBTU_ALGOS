#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	unsigned long long l = 0, r = 1e15, centre, cnt, sum;
	while (l < r) { 				
		centre = l + (r - l) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (centre < sum + arr[i]) {
				sum = 0;
				cnt++;
			}
			if (centre < arr[i]) {
				cnt = k + 1; 
			}
			sum += arr[i];
		}
		if (cnt > k) {
			l = centre + 1;
		} else if (cnt <= k) {
			r = centre;
		}
	}
	cout << l;
	return 0;
}