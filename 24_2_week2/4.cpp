// 2차원 배열의 합 bj.2167
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int arr[301][301];
	int n, m, k, arr_i, arr_j, x, y, sum;

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			cin >> arr[i][j];
	}
	cin >> k;
	for (int a=0; a<k; a++) {
		cin >> arr_i >> arr_j >> x >> y;
		sum = 0;
		for (int b=arr_i; b<=x; b++) {
			for (int c=arr_j; c<=y; c++)
				sum += arr[b][c];
		}
		cout << sum << '\n';
	}
	return (0);
}