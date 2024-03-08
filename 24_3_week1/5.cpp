// 구간 합 구하기 4
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int numbers[100001] = {0, };
	int n, m, number, start, end;

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> number;
		numbers[i] = numbers[i-1] + number;
	}
	for (int i=0; i<m; i++) {
		cin >> start >> end;
		cout << numbers[end] - numbers[start-1] << '\n';
	}
	return (0);
}