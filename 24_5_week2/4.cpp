// 평범한 배낭 bj.12865
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX(a, b) (a < b ? b : a)
using namespace std;

int bag[101][100001];
int w[101];
int v[101];

int main()
{
	fast;
	int n, k;

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> w[i] >> v[i];
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=k ; j++) {
			if (w[i] > j) bag[i][j] = bag[i-1][j];
			else bag[i][j] = MAX(bag[i-1][j], bag[i-1][j-w[i]] + v[i]);
		}
	}
	cout << bag[n][k];
	return (0);
}