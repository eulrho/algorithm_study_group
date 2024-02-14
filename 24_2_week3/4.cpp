// 성 지키기 bj.1236
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

int main()
{
	fast;
	int flag, row=0, col=0;
	string castle[51];

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> castle[i];
	for (int i=0; i<n; i++) {
		flag = 0;
		for (int j=0; j<m; j++)
			if (castle[i][j] == 'X') flag = 1;
		if (flag == 0) row++;
	}
	for (int i=0; i<m; i++) {
		flag = 0;
		for (int j=0; j<n; j++)
			if (castle[j][i] == 'X') flag = 1;
		if (flag == 0) col++;
	}
	cout << (row < col ? col : row);
	return (0);
}