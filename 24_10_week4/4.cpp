// 동물원 bj.1309
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	int arr[n+1];

	arr[1] = 3;
	arr[2] = 7;

	for (int i=3; i<=n; i++) {
		arr[i] = (arr[i - 2] + (arr[i - 1] + arr[i - 1]) % 9901) % 9901;
	}
	cout << arr[n];
	return 0;
}