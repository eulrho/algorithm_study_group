// 평균 bj.1546
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double sum=0;
	int arr[1001] = {0, }, n, max=0;

	cin >> n;
	for (int i=0; i<(int)n; i++) {
		cin >> arr[i];
		max = max < arr[i] ? arr[i] : max;
	}
	for (int i=0; i<(int)n; i++)
		sum += (double)arr[i] / max * 100.0;
	cout << (double)sum / n;
	return (0);
}