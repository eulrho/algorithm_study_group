// 귀여운 라이언 bj.15565
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1000000];
int arr_size;

int find_size(int k)
{
	int left=0, right=k-1, min=1000000, temp;

	if (right >= arr_size) return (-1);
	while (right < arr_size) {
		temp = arr[right] - arr[left] + 1;
		min = temp < min ? temp : min;
		left++; right++;
	}
	return (min);
}

int main()
{
	fast;
	int n, k, doll;

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> doll;
		if (doll == 1) {
			arr[arr_size] = i;
			arr_size++;
		}
	}
	cout << find_size(k);
	return (0);
}