// 특별상이라도 받고 싶어 bj.24460
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;

int find_num(int seats[][1024], int y_low, int y_high, int x_low, int x_high)
{
	int arr[4];
	if (y_high == y_low) return (seats[y_high][x_high]);
	if (y_high - y_low == 1) {
		arr[0] = seats[y_low][x_low];
		arr[1] = seats[y_low][x_high];
		arr[2] = seats[y_high][x_low];
		arr[3] = seats[y_high][x_high];
	}
	else {
		int y_mid = (y_low + y_high) / 2, x_mid = (x_low + x_high) / 2;

		arr[0] = find_num(seats, y_low, y_mid, x_low, x_mid);
		arr[1] = find_num(seats, y_mid + 1, y_high, x_low, x_mid);
		arr[2] = find_num(seats, y_low, y_mid, x_mid + 1, x_high);
		arr[3] = find_num(seats, y_mid + 1, y_high, x_mid + 1, x_high);
	}
	sort(arr, arr + 4);
	return (arr[1]);
}

int main()
{
	fast;
	int n; cin >> n;
	int seats[1024][1024];

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cin >> seats[i][j];
	}
	cout << find_num(seats, 0, n - 1, 0, n - 1);
	return (0);
}